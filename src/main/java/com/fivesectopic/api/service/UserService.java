package com.fivesectopic.api.service;

import com.fivesectopic.api.models.FriendGroup;
import com.fivesectopic.api.models.User;
import com.fivesectopic.api.repository.FriendGroupRepository;
import com.fivesectopic.api.repository.UserRepository;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RestController
@RequestMapping(value="/api/user")
public class UserService {
    @Autowired
    private UserRepository userRepository;

    @RequestMapping(value="/add", method= RequestMethod.POST)
    public String add(@RequestBody String json){
        JSONObject j = new JSONObject(json);
        String nickanme = (String) j.get("nickname");
        String password = (String) j.get("password");
        User user = new User();
        user.setNickname(nickanme);
        user.setPassword(password);

        user = userRepository.save(user);

        JSONObject outputJsonObj = new JSONObject();
        outputJsonObj.put("success", true);

        return outputJsonObj.toString();
    }
}
