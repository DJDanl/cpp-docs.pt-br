---
title: Erro das LNK1312 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1312
dev_langs:
- C++
helpviewer_keywords:
- LNK1312
ms.assetid: 48284abb-d849-43fc-ab53-45aded14fd8a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 335a3976675f36e3da295bc23c8e17440a56a505
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088638"
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