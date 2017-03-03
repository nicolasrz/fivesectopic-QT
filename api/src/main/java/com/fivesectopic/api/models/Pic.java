package com.fivesectopic.api.models;

import lombok.Data;

import javax.persistence.*;


/**
 * Created by Nicolas on 03/03/2017.
 */
@Entity
@Data
public class Pic {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private long id;

    @OneToOne
    private User user;

    private int privacy;
    private String sendNotification;
    private String openApp;

    @Lob
    private String photo;

}
