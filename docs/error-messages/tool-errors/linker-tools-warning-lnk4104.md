---
title: Aviso LNK4104 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4104
helpviewer_keywords:
- LNK4104
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
ms.openlocfilehash: 604dccf01b3dffc0060546bebf19d64c16ebf965
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193960"
---
# <a name="linker-tools-warning-lnk4104"></a>Aviso LNK4104 (Ferramentas de Vinculador)

a exportação do símbolo ' Symbol ' deve ser privada

O `symbol` pode ser um dos seguintes:

- `DllCanUnloadNow`

- `DllGetClassObject`

- `DllGetClassFactoryFromClassString`

- `DllGetDocumentation`

- `DllInitialize`

- `DllInstall`

- `DllRegisterServer`

- `DllRegisterServerEx`

- `DllRegisterServerExW`

- `DllUnload`

- `DllUnregisterServer`

- `RasCustomDeleteEntryNotify`

- `RasCustomDial`

- `RasCustomDialDlg`

- `RasCustomEntryDlg`

Esse aviso é emitido quando você está criando uma biblioteca de importação para uma DLL e exporta uma das funções acima sem especificá-la como particular no arquivo de definição de módulo. Em geral, essas funções são exportadas para uso somente pelo OLE. Colocá-los na biblioteca de importação pode levar a um comportamento incomum quando um programa vinculado à biblioteca faz chamadas a eles incorretamente. Para obter mais informações sobre a palavra-chave PRIVATE, consulte [Exports](../../build/reference/exports.md).
