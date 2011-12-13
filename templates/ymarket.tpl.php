<?php
/**
 * @param $nodes
 *  Массив нод, которые опубликованы в маркете.
 * @param $categories
 *  Термины таксономии, которые являются категорими для маркета.
 * @param $vid
 *  ИД словаря, к которому принадлежат категории
*/
?>
<?php echo '<?xml version="1.0" encoding="utf-8"?>' . "\n"; ?>
<!DOCTYPE yml_catalog SYSTEM "shops.dtd">
<yml_catalog date="<?php echo $date ?>">
  <shop>
  <?php if ($name) { ?>
    <name><?php echo $name; ?></name>
  <?php } ?>
  <?php if ($company) { ?>
    <company><?php echo $company; ?></company>
  <?php } ?>
  <?php if ($url) { ?>
    <url><?php echo $url; ?></url>
  <?php } ?>
  <?php if ($platform) { ?>
    <platform><?php echo $platform; ?></platform>
  <?php } ?>
  <?php if ($version) { ?>
    <version><?php echo $version; ?></version>
  <?php } ?>
  <?php if ($agency) { ?>
    <agency><?php echo $agency; ?></agency>
  <?php } ?>
  <?php if ($email) { ?>
    <email><?php echo $email; ?></email>
  <?php } ?>
    <currencies>
      <currency id="RUR" rate="1"/>
    </currencies>
  <?php if ($categories) { ?>
    <categories>
    <?php foreach ($categories as $k => $category) { ?>
      <category id="<?php echo $category->tid; ?>"<?php echo ($category->parents[0]) ? ' parentId="' . $category->parents[0] . '"' : ''; ?>><?php echo $category->name; ?></category>
    <?php } ?>
    </categories>
  <?php } ?>
  <?php if ($nodes) { ?>
    <offers>
    <?php foreach ($nodes as $node) { ?>
      <offer id="<?php echo $node->nid; ?>" available="<?php echo $node->available ? 'true' : 'false'; ?>">
        <url><?php echo $node->url; ?></url>
        <price><?php echo $node->sell_price; ?></price>
        <currencyId>RUR</currencyId>
        <categoryId><?php echo $node->categoryId; ?></categoryId>
      <?php if ($node->picture) { ?>
        <picture><?php echo $node->picture; ?></picture>
      <?php } ?>
      <?php if ($node->vendor) { ?>
        <vendor><?php echo $node->vendor; ?></vendor>
      <?php } ?>
        <name><?php echo $node->title; ?></name>
      <?php if ($node->body) { ?>
        <description><?php echo $node->body; ?></description>
      <?php } ?>
      </offer>
    <?php } ?>
    </offers>
  <?php } ?>
  </shop>
</yml_catalog>
