---
title: Aviso LNK4104 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4104
helpviewer_keywords:
- LNK4104
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
ms.openlocfilehash: 3d89b27c32b33b917abb7fc140eebf5924142423
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50668100"
---
# <a name="linker-tools-warning-lnk4104"></a>Aviso LNK4104 (Ferramentas de Vinculador)

exportação de símbolo 'symbol' deve ser PRIVATE

O `symbol` pode ser uma das seguintes opções:

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

Esse aviso é emitido quando você estiver criando uma biblioteca de importação para uma DLL e exportar uma das funções acima sem especificá-lo como particular no arquivo de definição de módulo. Em geral, essas funções são exportadas para uso somente pelo OLE. Colocando-as na biblioteca de importação pode resultar em comportamento incomum quando um programa vinculado à biblioteca incorretamente faz chamadas para eles. Para obter mais informações sobre a palavra-chave PRIVADA, consulte [exportações](../../build/reference/exports.md).