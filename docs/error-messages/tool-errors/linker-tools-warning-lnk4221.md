---
title: Aviso LNK4221 (Ferramentas de Vinculador)
ms.date: 11/04/2016
f1_keywords:
- LNK4221
helpviewer_keywords:
- LNK4221
ms.assetid: 8e2eb2de-9532-4b85-908a-8c9ff5c4cccb
ms.openlocfilehash: baea8643001c550aeb3cb35dc6fe414e4330c0c1
ms.sourcegitcommit: afd6fac7c519dbc47a4befaece14a919d4e0a8a2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2018
ms.locfileid: "51523462"
---
# <a name="linker-tools-warning-lnk4221"></a>Aviso LNK4221 (Ferramentas de Vinculador)

Esse arquivo de objeto não define nenhum dos símbolos anteriormente indefinidos, portanto, não será usado por qualquer operação de vínculo que consuma esta biblioteca

Considere os seguintes dois trechos de código.

```
// a.cpp
#include <atlbase.h>
```

```
// b.cpp
#include <atlbase.h>
int function()
{
   return 0;
}
```

Para compilar os arquivos e criar dois arquivos de objeto, execute **cl /c a.cpp b.cpp** em um prompt de comando. Se você vincular os arquivos de objeto executando **vincular/lib /out:test.lib a.obj b.obj**, você receberá o aviso LNK4221. Se você vincular os objetos, executando **vincular/lib /out:test.lib b.obj a.obj**, você não receberá um aviso.

Nenhum aviso é emitido no segundo cenário, porque o vinculador opera de maneira último a entrar primeiro a sair (UEPS). No primeiro cenário, b.obj é processada antes a.obj e a.obj não tem novos símbolos para adicionar. Ao instruir o vinculador processar a.obj pela primeira vez, você pode evitar o aviso.

Uma causa comum desse erro é quando dois arquivos de origem especificam a opção [/Yc (criar a arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome de arquivo de cabeçalho especificado na **cabeçalho pré-compilado** campo. Uma causa comum desse problema lida com Stdafx. h, já que, por padrão, o Stdafx inclui Stdafx. h e não adiciona qualquer novo símbolo. Se outro arquivo de origem inclui Stdafx. h com **/Yc** e o arquivo. obj associado é processado antes de Stdafx. obj, o vinculador gerará LNK4221.

Uma maneira de resolver esse problema é ter certeza de que para cada cabeçalho pré-compilado, há apenas um arquivo de origem que inclui-lo com **/Yc**. Todos os outros arquivos de origem devem usar cabeçalhos pré-compilados. Para obter mais informações sobre como alterar essa configuração, consulte [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md).