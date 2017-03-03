package com.fivesectopic.api.service;

import com.fivesectopic.api.models.FriendGroup;
import com.fivesectopic.api.models.User;
import com.fivesectopic.api.repository.FriendGroupRepository;
import com.fivesectopic.api.repository.UserRepository;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RestController
@RequestMapping(value="/api/friendgroup")
public class FriendGroupService {
    @Autowired
    private FriendGroupRepository friendGroupRepository;

    @Autowired
    private UserRepository userRepository;

    @RequestMapping(value="/add", method= RequestMethod.POST)
    public String add(@RequestBody String json){
        JSONObject j = new JSONObject(json);
        String name = (String) j.get("name");
        FriendGroup fg = new FriendGroup();
        fg.setName(name);
        fg = friendGroupRepository.save(fg);

        JSONObject outputJsonObj = new JSONObject();
        outputJsonObj.put("success", true);

        return outputJsonObj.toString();
    }

    @RequestMapping(value="/adduser", method= RequestMethod.POST)
    public String adduser(@RequestBody String json){
        JSONObject j = new JSONObject(json);
        long id_user = (int) j.get("id_user");
        long id_friendgroup = (int) j.get("id_friend_group");
        User userToInsert = userRepository.findById(id_user);

        FriendGroup friendGroup = friendGroupRepository.findById(id_friendgroup);
        List<User> users =  friendGroup.getUsers();
        users.add(userToInsert);
        friendGroup.setUsers(users);
        friendGroup = friendGroupRepository.save(friendGroup);


        JSONObject outputJsonObj = new JSONObject();
        outputJsonObj.put("success", true);

        return outputJsonObj.toString();
    }

    @RequestMapping(value="/users/{group_name}", method= RequestMethod.GET)
    public String userByGroupName(@PathVariable String group_name) {

        FriendGroup fg = friendGroupRepository.findByName(group_name);
        List<User> users = fg.getUsers();
        StringBuilder allUsers = new StringBuilder();
        for (User user : users){
            allUsers.append(String.valueOf(user.getId()) + ";");
        }
        return allUsers.toString();

    }

    @RequestMapping(value="/users/user/{user_id}", method= RequestMethod.GET)
    public String getFriendByUser(@PathVariable String user_id) {

        long paramId = Long.valueOf(user_id).longValue();

        List<FriendGroup> fg = friendGroupRepository.findAll();

        String groupName="";

        for(FriendGroup group : fg){
            List<User> users = group.getUsers();
            for(User u :users){
                if(u.getId() == paramId){
                   groupName = group.getName();
                }
            }
        }

        FriendGroup fa = friendGroupRepository.findByName(groupName);
        List<User> usersF = fa.getUsers();
        StringBuilder allUsers = new StringBuilder();
        for (User user : usersF){
            allUsers.append(String.valueOf(user.getId()) + "#");
        }
        allUsers.deleteCharAt(allUsers.length()-1);
        return allUsers.toString();

    }
}
