---
title: Ferramentas de vinculador LNK4104 aviso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4104
dev_langs:
- C++
helpviewer_keywords:
- LNK4104
ms.assetid: ca6728db-d616-419a-a570-65e8445c6079
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6304f3ea928c89f4756a4594270ebb7914324f85
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46057256"
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