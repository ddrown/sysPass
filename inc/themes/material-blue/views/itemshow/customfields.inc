<?php

/** @var $icons \Theme\Icons */
/** @var \SP\DataModel\CustomFieldDefData $field */

?>

<div id="fancyContainer" align="center">
    <h2><?php echo $header; ?></H2>

    <form method="post" name="frmCustomFields" id="frmCustomFields" class="form-action"
          data-onsubmit="appMgmt/save"
          data-activetab="<?php echo isset($activeTab) ? $activeTab : ''; ?>"
          data-nextaction-id="<?php echo \SP\Core\ActionsInterface::ACTION_MGM_CUSTOMFIELDS; ?>">
        <table class="fancydata">
            <tbody>
            <tr>
                <td class="descField"><?php echo _('Nombre'); ?></td>
                <td class="valField">
                    <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                        <input id="name" name="name" type="text" required
                               class="mdl-textfield__input mdl-color-text--indigo-400"
                               maxlength="50" value="<?php echo $field->getName(); ?>">
                        <label class="mdl-textfield__label"
                               for="name"><?php echo _('Nombre del campo'); ?></label>
                    </div>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Tipo'); ?></td>
                <td class="valField">
                    <select name="type" id="sel-type" size="1" class="select-box">
                        <?php foreach ($types as $id => $type): ?>
                            <option
                                value='<?php echo $id; ?>' <?php echo ($id === $field->getType()) ? 'selected' : ''; ?>><?php echo $type[1]; ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Módulo'); ?></td>
                <td class="valField">
                    <select name="module" id="sel-module" size="1" class="select-box">
                        <?php foreach ($modules as $id => $module): ?>
                            <option
                                value='<?php echo $id; ?>' <?php echo ($id === $field->getModule()) ? 'selected' : ''; ?>><?php echo $module; ?></option>
                        <?php endforeach; ?>
                    </select>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Texto Ayuda'); ?></td>
                <td class="valField">
                    <div class="mdl-textfield mdl-js-textfield mdl-textfield--floating-label">
                        <input id="help" name="help" type="text" class="mdl-textfield__input mdl-color-text--indigo-400"
                               value="<?php echo $field->getHelp(); ?>">
                        <label class="mdl-textfield__label"
                               for="help"><?php echo _('Ayuda del campo'); ?></label>
                    </div>
                </td>
            </tr>
            <tr>
                <td class="descField"><?php echo _('Obligatorio'); ?></td>
                <td class="valField">
                    <label class="mdl-switch mdl-js-switch mdl-js-ripple-effect" for="required">
                        <input type="checkbox" id="required" class="mdl-switch__input mdl-color-text--indigo-400"
                               name="required"
                            <?php echo $field->isRequired() ? 'checked' : ''; ?>/>
                        <span class="mdl-switch__label"></span>
                    </label>
                </td>
            </tr
            </tbody>
        </table>

        <input type="hidden" name="itemId" value="<?php echo $field->getId(); ?>"/>
        <input type="hidden" name="actionId" value="<?php echo $actionId; ?>"/>
        <input type="hidden" name="sk" value="">
        <input type="hidden" name="isAjax" value="1">
    </form>
    <div id="resCheck"><span id="resFancyAccion"></span></div>
    <div class="action-in-box">
        <button
            class="mdl-button mdl-js-button mdl-button--fab mdl-button--mini-fab mdl-button--colored <?php echo $icons->getIconSave()->getClassButton(); ?>"
            form="frmCustomFields" title="<?php echo $icons->getIconSave()->getTitle(); ?>">
            <i class="material-icons"><?php echo $icons->getIconSave()->getIcon(); ?></i>
        </button>
    </div>
</div>
<script>
    sysPassApp.sk.set("<?php echo $sk; ?>");
</script>