---
title: Aviso LNK4222 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4222
helpviewer_keywords:
- LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
ms.openlocfilehash: 52a4fee532eb9997dcf013f95246b27fdffc4c20
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160400"
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