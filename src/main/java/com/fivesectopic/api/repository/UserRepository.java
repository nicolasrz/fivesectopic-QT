package com.fivesectopic.api.repository;

import com.fivesectopic.api.models.User;
import org.springframework.data.repository.PagingAndSortingRepository;
import org.springframework.data.repository.query.Param;
import org.springframework.data.rest.core.annotation.RepositoryRestResource;

import java.util.List;

/**
 * Created by Nicolas on 03/03/2017.
 */
@RepositoryRestResource(collectionResourceRel = "user", path = "user")
public interface UserRepository extends PagingAndSortingRepository<User, Long> {
    User findById(@Param("id")Long id);
    User findByNicknameAndPassword(@Param("nickname") String nickname, @Param("password") String password);
}
