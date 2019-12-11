---
title: Erro das Ferramentas de Vinculador LNK1312
ms.date: 11/04/2016
f1_keywords:
- LNK1312
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
ms.openlocfilehash: e462d24f2eb54718ba73617146aab96bb14a66df
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74990913"
---
# <a name="linker-tools-error-lnk1312"></a>Erro das Ferramentas de Vinculador LNK1312

arquivo inválido ou corrompido: não é possível importar o assembly

Ao criar um assembly, um arquivo que não seja um módulo ou assembly compilado com **/CLR** foi passado para a opção de vinculador **/ASSEMBLYMODULE** .  Se você passou um arquivo de objeto para **/ASSEMBLYMODULE**, basta passar o objeto diretamente para o vinculador, em vez de **/ASSEMBLYMODULE**.

## <a name="example"></a>Exemplo

O exemplo a seguir criou o arquivo. obj.

```cpp
// LNK1312.cpp
// compile with: /clr /LD
public ref class A {
public:
   int i;
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera LNK1312.

```cpp
// LNK1312_b.cpp
// compile with: /clr /LD /link /assemblymodule:LNK1312.obj
// LNK1312 error expected
public ref class M {};
```
