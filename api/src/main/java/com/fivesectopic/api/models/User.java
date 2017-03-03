package com.fivesectopic.api.models;

import lombok.Data;

import javax.persistence.*;
import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@Entity
@Data
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private long id;
    private String nickname;
    private String password;

}
