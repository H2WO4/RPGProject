#  Map folder

## Map format

First line is header

```
<width> <height> <layers> <objects>
```

Then layers are defined. There are width * height tiles per layer, with 1 to 3 layers.

```
<tile1> <tile2> ...
```

Finally objects.

```
<type> <x> <y> <properties>
```

| Object type | Description | Properties |
| ------------- | ------------- | ------------ |
| teleport | Teleport player to another location | `<map> <x> <y>` |
