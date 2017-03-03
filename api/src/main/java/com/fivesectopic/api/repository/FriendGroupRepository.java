package com.fivesectopic.api.repository;

import com.fivesectopic.api.models.FriendGroup;
import com.fivesectopic.api.models.User;
import org.springframework.data.repository.PagingAndSortingRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */

@RepositoryRestResource(collectionResourceRel = "friendgroup", path = "friendgroup")
public interface FriendGroupRepository extends PagingAndSortingRepository<FriendGroup, Long> {
    FriendGroup findById(@Param("id")Long id);
    FriendGroup findByName(@Param("name") String name);
    List<FriendGroup> findAll();
}
