---
title: Ferramentas de vinculador LNK4222 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4222
dev_langs:
- C++
helpviewer_keywords:
- LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: abc4f85fbc361b37d9325f9d395a1c34e1eeed2e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106916"
---
# <a name="linker-tools-warning-lnk4222"></a>Aviso LNK4222 (Ferramentas de Vinculador)

símbolo exportado 'symbol' não deve ser atribuído um número ordinal

Os símbolos a seguir não devem ser exportados por ordinal:

- `DllCanUnloadNow`

- `DllGetClassObject`

- `DllGetClassFactoryFromClassString`

- `DllInstall`

- `DllRegisterServer`

- `DllRegisterServerEx`

- `DllUnregisterServer`

Essas funções sempre estão localizadas por nome, usando `GetProcAddress`. O vinculador avisa sobre esse tipo de exportação é porque isso poderia resultar em uma imagem maior. Isso pode ocorrer se o intervalo de suas exportações ordinal é grande com relativamente poucas exportações. Por exemplo,

```
EXPORTS
   DllGetClassObject   @1
   MyOtherAPI      @100
```

exigirá a 100 slots na tabela de endereço de exportação com 98 ao preenchimento de (2-99) apenas. Por outro lado

```
EXPORTS
   DllGetClassObject
   MyOtherAPI      @100
```

exigirá dois slots. (Lembre-se de que você também pode exportar com o [/exportação](../../build/reference/export-exports-a-function.md) a opção de vinculador.)