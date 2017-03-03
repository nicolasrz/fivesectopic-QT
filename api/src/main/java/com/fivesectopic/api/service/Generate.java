package com.fivesectopic.api.service;

import com.fivesectopic.api.models.FriendGroup;

import com.fivesectopic.api.models.Pic;
import com.fivesectopic.api.models.User;
import com.fivesectopic.api.repository.FriendGroupRepository;
import com.fivesectopic.api.repository.PicRepository;
import com.fivesectopic.api.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RestController
@RequestMapping(value="/api")
public class Generate {
    @Autowired
    private UserRepository userRepository;

    @Autowired
    private FriendGroupRepository friendGroupRepository;

    @Autowired
    private PicRepository picRepository;

    @RequestMapping(value="/generate", method= RequestMethod.GET)
    public String generateValue() {
        List<User> users = new ArrayList<>();



        User user1 = new User();
        user1.setNickname("user1");
        user1.setPassword("password");
        user1 = userRepository.save(user1);

        for(int i =2; i < 6 ; i++){
            User user = new User();
            user.setNickname("user"+i);
            user.setPassword("password"+i);
            user = userRepository.save(user);
            users.add(user);
        }

        FriendGroup friendGroup = new FriendGroup();
        friendGroup.setName("Group1");
        friendGroup.setUsers(users);
        friendGroup = friendGroupRepository.save(friendGroup);

        Pic pic = new Pic();

        pic.setPrivacy(0);
        pic.setUser(user1);
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = new Date();
        String sendNotificationDate = dateFormat.format(date);
        String openAppDate = dateFormat.format(date);
        pic.setOpenApp(openAppDate);
        pic.setSendNotification(sendNotificationDate);

        pic = picRepository.save(pic);



        //JSONObject outputJsonObj = new JSONObject();
        //outputJsonObj.put("borders", borders);
        //
        return "true";
    }

}
