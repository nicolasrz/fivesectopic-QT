package com.fivesectopic.api.repository;

import com.fivesectopic.api.models.Pic;
import com.fivesectopic.api.models.User;
import org.springframework.data.repository.PagingAndSortingRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RepositoryRestResource(collectionResourceRel = "pic", path = "pic")
public interface PicRepository extends PagingAndSortingRepository<Pic, Long> {
    Pic findById(@Param("id")Long id);
    List<Pic> findByUser(@Param("user") User user);
    List<Pic> findAll();
}
