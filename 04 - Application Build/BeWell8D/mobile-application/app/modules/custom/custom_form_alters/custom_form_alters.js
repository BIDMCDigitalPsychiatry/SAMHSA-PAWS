/**
 * Implements hook_form_alter().
 */
function custom_form_alters_form_alter(form, form_state, form_id) {
  switch (form_id) {
    case 'user_login_form':
      //Remove Form Buttons we added to the page.
      form.buttons = {};
      
      //Add Button classes to the submit button
      form.elements.submit.options.attributes.class = 'btn m-top m-btm-small';
      
      //Set weight to elements
      form.elements.name.weight = 0;
      form.elements.pass.weight = 1;
      form.elements.submit.weight = 3;
      
      //Insert login notice
      var noticeMarkup = '<div class="login-notice full-width-bar-grey"><p>You are accessing a mobile application provided ';
      noticeMarkup += 'by an agency of the U.S. Government. System usage may be monitored, recorded, ';
      noticeMarkup += 'and subject to audit. Unauthorized use of the system is prohibited and subject to ';
      noticeMarkup += 'criminal and civil penalties. Use of the system indicates consent to monitoring';
      noticeMarkup += 'and recording.</p></div>';
      form.elements.notice = {
        'markup': noticeMarkup,
        'weight': 2,
      };
        
      //console.log(form);
      break;
    case 'user_register_form':
      
      //Set weight to elements
      form.elements.conf_mail.weight = 0;
      form.elements.mail.weight = 1;
      form.elements.name.weight = 2;
      form.elements.pass.weight = 3;
      form.elements.pass2.weight = 4;
      form.elements.submit.weight = 7;
      
      //Add Button classes to the submit button
      form.elements.submit.options.attributes.class = 'btn m-top-large m-btm-small';
      
      //Insert pass requirement
      form.elements.pass2.description = '<ul>';
      form.elements.pass2.description += '<li>- Password must contain at least one uppercase character, one lowercase character, one digit, and one punctuation character.</li>';
      form.elements.pass2.description += '<li>- Password must not contain the username.</li>';
      form.elements.pass2.description += '<li>- Password must be at least 8 characters in length.</li>';
      form.elements.pass2.description += '<li>- You will be asked to update your password every 60 days.</li>';
      form.elements.pass2.description += '</ul>';
      
      //Insert Requirement Check notice
      var appVars = variable_get('appVars');
        if (typeof appVars !== 'undefined') {
          appVars = JSON.parse(appVars);
        var checkMarkup = '<div class="requirement-check-notice full-width-bar-grey"><p style="margin-bottom: 0px;">To access <strong>' + appVars.appTitle + '</strong>, all users are '; 
        checkMarkup += 'required to read and accept SAMHSA’s Rules of Behavior for Use of HHS Information Resources (Rules).  ';
        checkMarkup += 'Please read the <a href="https://www.hhs.gov/ocio/policy/hhs-rob.html" target="_blank" style="color: blue; text-decoration: underline;">Rules</a> and select the ';
        checkMarkup += 'checkbox below for "I agree." Hitting submit will act as your digital acknowledgement of having read ';
        checkMarkup += 'and agreeing to adhere to the Rules.</p></div>';
        form.elements.requiremntchecknotice = {
          'markup': checkMarkup,
          'weight': 5,
        };
      }
      
      //Insert Account Requirement Check
      form.elements.requiremntcheck = {};
      form.elements.requiremntcheck.title = 'I Agree';
      form.elements.requiremntcheck.type = 'checkbox';
      form.elements.requiremntcheck.required = true;
      form.elements.requiremntcheck.weight = 6;
      form.elements.requiremntcheck.prefix = '<div class="requirement-check full-width-bar-grey" style="margin-top: 0px; padding-bottom: 10px;">';
      form.elements.requiremntcheck.suffix = '</div>';
      
      //console.log(form);
      break;
    case 'user_pass_form':
      //Add Button classes to the submit button
      form.elements.submit.options.attributes.class = 'btn m-top-large m-btm-small';
      
      //Custom Submit Function
      form.submit['0'] = 'app_user_pass_form_submit';
      
      //console.log(form);
      break;
    case 'user_profile_form':
      
      //Set weight to elements
      form.elements.current_pass.weight = 0;
      form.elements.mail.weight = 1;
      form.elements.name.weight = 2;
      form.elements.pass_pass1.weight = 3;
      form.elements.pass_pass2.weight = 4;
      form.elements.submit.weight = 7;
      
      var args = arg();
      form.elements.field_user_settings_node.access = false;
      form.buttons.cancel.access = false;
      form.elements.submit.value = 'Save User Settings';
      form.elements.submit.options.attributes.class = 'btn m-top-large';
      form.action = 'app_my_account';
      form.elements.current_pass.prefix = '<div class="description">Enter your current password to change the E-mail address or Password.</div>';
      form.elements.pass_pass1.title = "New Password";
      form.elements.pass_pass2.title = "Confirm New Password";
      form.elements.pass_pass2.description = '<ul>';
      form.elements.pass_pass2.description += '<li>- Password must contain at least one uppercase character, one lowercase character, one digit, and one punctuation character.</li>';
      form.elements.pass_pass2.description += '<li>- Password must not contain the username.</li>';
      form.elements.pass_pass2.description += '<li>- Password must be at least 8 characters in length.</li>';
      form.elements.pass_pass2.description += '<li>- Password must not match last 6 passwords.</li>';
      form.elements.pass_pass2.description += '<li>- You will be asked to update your password every 60 days.</li>';
      form.elements.pass_pass2.description += '</ul>';
      form.elements.current_pass.suffix = '<hr class="hr-medium"><div class="description">To change the current user password, enter the new password in both fields.</div>';
      form.elements.current_pass.description = ""; // Remove element
      //console.log(form);
      
      //Insert Requirement Check notice
      var appVars = variable_get('appVars');
        if (typeof appVars !== 'undefined') {
          appVars = JSON.parse(appVars);
        var checkMarkup = '<div class="requirement-check-notice full-width-bar-grey"><p style="margin-bottom: 0px;">To access <strong>' + appVars.appTitle + '</strong>, all users are '; 
        checkMarkup += 'required to read and accept SAMHSA’s Rules of Behavior for Use of HHS Information Resources (Rules).  ';
        checkMarkup += 'Please read the <a href="https://www.hhs.gov/ocio/policy/hhs-rob.html" target="_blank" style="color: blue; text-decoration: underline;">Rules</a> and select the ';
        checkMarkup += 'checkbox below for "I agree." Hitting submit will act as your digital acknowledgement of having read ';
        checkMarkup += 'and agreeing to adhere to the Rules.</p></div>';
        form.elements.requiremntchecknotice = {
          'markup': checkMarkup,
          'weight': 5,
        };
      }
      
      //Insert Account Requirement Check
      form.elements.requiremntchecks = {};
      form.elements.requiremntchecks.title = 'I Agree';
      form.elements.requiremntchecks.type = 'checkbox';
      form.elements.requiremntchecks.required = true;
      form.elements.requiremntchecks.weight = 6;
      form.elements.requiremntchecks.prefix = '<div class="requirement-check full-width-bar-grey" style="margin-top: 0px; padding-bottom: 10px;">';
      form.elements.requiremntchecks.suffix = '</div>';
      
      if (args[1] == 'force_reset_password') {
        form.elements.current_pass.prefix = '<div class="description">Enter your current password to change the Password.</div>';
        form.elements.name.access = false;
        form.elements.mail.access = false;
        form.elements.name.required = false;
        form.elements.mail.required = false;
      }
      
      //console.log(form);
      break;
    case 'custom_pages_app_my_account_edit_app__form':
      form.buttons.cancel.access = false;
      form.elements.submit.value = 'Save App Settings';
      form.elements.submit.options.attributes.class = 'btn m-top-large';
      form.options.attributes.class = "form-app-settings";
      //console.log(form);
      break;
  }
}


/**
 * The custom request new password form submission handler.
 */
function app_user_pass_form_submit(form, form_state) {
  user_request_new_password(form_state.values['name'], {
      success: function(result) {
        if (result[0]) {
          var msg = t('Further instructions have been sent to your e-mail address.');
          drupalgap_set_message(msg);
        }
        else {
          var msg = t('There was a problem sending an e-mail to your address.');
          drupalgap_set_message(msg, 'warning');
        }
        drupalgap_goto('app_user_login');
      }
  });
}