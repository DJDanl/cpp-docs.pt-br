---
title: Erro das Ferramentas de Vinculador LNK1312
ms.date: 11/04/2016
f1_keywords:
- LNK1312
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
ms.openlocfilehash: 49fa7e7963d6bb561e1602b58fe1f26c5f3d54bd
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160465"
---
# <a name="linker-tools-error-lnk1312"></a>Erro das Ferramentas de Vinculador LNK1312

arquivo inválido ou corrompido: não é possível importar o assembly

Ao criar um assembly, um arquivo que não seja um módulo ou assembly compilado com **/clr** foi passado para o **/ASSEMBLYMODULE** a opção de vinculador.  Se você passar um arquivo do objeto **/ASSEMBLYMODULE**, basta passar o objeto diretamente para o vinculador, em vez de ao **/ASSEMBLYMODULE**.

## <a name="example"></a>Exemplo

O exemplo a seguir criado o arquivo. obj.

```
// LNK1312.cpp
// compile with: /clr /LD
public ref class A {
public:
   int i;
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera das LNK1312.

```
// LNK1312_b.cpp
// compile with: /clr /LD /link /assemblymodule:LNK1312.obj
// LNK1312 error expected
public ref class M {};
```