package com.fivesectopic.api.models;

import lombok.Data;

import javax.persistence.*;
import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@Entity
@Data
public class FriendGroup {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private long id;

    private String name;
    @OneToMany
    private List<User> users;
}
