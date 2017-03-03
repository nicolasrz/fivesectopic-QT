package com.fivesectopic.api.service;

import com.fivesectopic.api.models.FriendGroup;
import com.fivesectopic.api.models.Pic;
import com.fivesectopic.api.models.User;
import com.fivesectopic.api.repository.FriendGroupRepository;
import com.fivesectopic.api.repository.PicRepository;
import com.fivesectopic.api.repository.UserRepository;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.HashMap;
import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RestController
@RequestMapping(value="/api/pic")
public class PicService {
    @Autowired
    private PicRepository picRepository;

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private FriendGroupRepository friendGroupRepository;

    @RequestMapping(value="/pics/{group_name}", method= RequestMethod.GET)
    public String getBorderByYearMonthDay(@PathVariable String group_name) {

        FriendGroup fg = friendGroupRepository.findByName(group_name);
        List<User> users = fg.getUsers();
        HashMap<String, List<Pic>> map = new HashMap<>();

        for(User user : users){
            List<Pic> pics = picRepository.findByUser(user);
            map.put(user.getNickname(), pics);
        }


        JSONObject outputJsonObj = new JSONObject();
        outputJsonObj.put("pics_group", map);
        return outputJsonObj.toString();
    }
}
