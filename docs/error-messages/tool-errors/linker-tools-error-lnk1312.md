---
title: Erro das Ferramentas de Vinculador LNK1312
ms.date: 11/04/2016
f1_keywords:
- LNK1312
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
ms.openlocfilehash: 69af2bd2c22fdb1188cf0b7119791e451e80f966
ms.sourcegitcommit: c1fd917a8c06c6504f66f66315ff352d0c046700
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/16/2020
ms.locfileid: "90686490"
---
# <a name="linker-tools-error-lnk1312"></a>Erro das Ferramentas de Vinculador LNK1312

arquivo inválido ou corrompido: não é possível importar o assembly

Ao criar um assembly, um arquivo que não seja um módulo ou assembly compilado com **/CLR** foi passado para a opção de vinculador **/ASSEMBLYMODULE** .  Se você passou um arquivo de objeto para **/ASSEMBLYMODULE**, basta passar o objeto diretamente para o vinculador, em vez de **/ASSEMBLYMODULE**.

## <a name="examples"></a>Exemplos

O exemplo a seguir criou o arquivo. obj.

```cpp
// LNK1312.cpp
// compile with: /clr /LD
public ref class A {
public:
   int i;
};
```

O exemplo a seguir gera LNK1312.

```cpp
// LNK1312_b.cpp
// compile with: /clr /LD /link /assemblymodule:LNK1312.obj
// LNK1312 error expected
public ref class M {};
```
