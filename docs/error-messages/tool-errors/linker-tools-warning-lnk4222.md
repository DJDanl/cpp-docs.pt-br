---
title: Aviso LNK4222 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4222
helpviewer_keywords:
- LNK4222
ms.assetid: b7bb1794-41fb-4c83-b9b0-59c0d786a7da
ms.openlocfilehash: f74379861ad04142fd78a8e307af165072c9cadd
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183027"
---
# <a name="linker-tools-warning-lnk4222"></a>Aviso LNK4222 (Ferramentas de Vinculador)

símbolo exportado ' Symbol ' não deve ser atribuído a um ordinal

Os seguintes símbolos não devem ser exportados por ordinal:

- `DllCanUnloadNow`

- `DllGetClassObject`

- `DllGetClassFactoryFromClassString`

- `DllInstall`

- `DllRegisterServer`

- `DllRegisterServerEx`

- `DllUnregisterServer`

Essas funções são sempre localizadas por nome, usando `GetProcAddress`. O vinculador avisa sobre esse tipo de exportação porque pode resultar em uma imagem maior. Isso pode acontecer se o intervalo de suas exportações ordinais for grande com relativamente poucas exportações. Por exemplo,

```
EXPORTS
   DllGetClassObject   @1
   MyOtherAPI      @100
```

exigirá 100 slots na tabela de endereços de exportação com 98 (2-99) apenas o preenchedor. Por outro lado

```
EXPORTS
   DllGetClassObject
   MyOtherAPI      @100
```

precisará de dois slots. (Lembre-se de que você também pode exportar com a opção de vinculador [/Export](../../build/reference/export-exports-a-function.md) .)
