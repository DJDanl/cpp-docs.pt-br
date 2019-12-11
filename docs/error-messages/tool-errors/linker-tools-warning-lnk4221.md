---
title: Aviso LNK4221 (Ferramentas de Vinculador)
ms.date: 08/19/2019
f1_keywords:
- LNK4221
helpviewer_keywords:
- LNK4221
ms.assetid: 8e2eb2de-9532-4b85-908a-8c9ff5c4cccb
ms.openlocfilehash: fb355b6d004d9488abac89ef44c9ec38c791ffda
ms.sourcegitcommit: 573b36b52b0de7be5cae309d45b68ac7ecf9a6d8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/10/2019
ms.locfileid: "74988031"
---
# <a name="linker-tools-warning-lnk4221"></a>Aviso LNK4221 (Ferramentas de Vinculador)

Este arquivo de objeto não define nenhum símbolo público não definido anteriormente, portanto, ele não será usado por nenhuma operação de link que consuma essa biblioteca

Considere os dois trechos de código a seguir.

```cpp
// a.cpp
#include <atlbase.h>
```

```cpp
// b.cpp
#include <atlbase.h>
int function()
{
   return 0;
}
```

Para compilar os arquivos e criar dois arquivos de objeto, execute **cl/c a. cpp b. cpp** em um prompt de comando. Se você vincular os arquivos de objeto executando o **link/lib/out: Test. lib a. obj b. obj**, você receberá o aviso LNK4221. Se você vincular os objetos executando o **link/lib/out: Test. lib b. obj a. obj**, você não receberá um aviso.

Nenhum aviso é emitido no segundo cenário porque o vinculador opera em uma maneira UEPS (último a entrar, primeiro a sair). No primeiro cenário, b. obj é processado antes de um. obj e um. obj não tem novos símbolos a serem adicionados. Ao instruir o vinculador para processar um. obj primeiro, você pode evitar o aviso.

::: moniker range=">=vs-2019"

Uma causa comum desse erro é quando dois arquivos de origem especificam a opção [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome de arquivo de cabeçalho especificado no campo de **cabeçalho pré-compilado** . Uma causa comum desse problema trata do *PCH. h* , já que, por padrão, *PCH. cpp* inclui *PCH. h* e não adiciona nenhum novo símbolo. Se outro arquivo de origem incluir *PCH. h* com **/YC** e o arquivo. obj associado for processado antes de PCH. obj, o vinculador gerará LNK4221.

::: moniker-end

::: moniker range="<=vs-2017"

Uma causa comum desse erro é quando dois arquivos de origem especificam a opção [/Yc (criar arquivo de cabeçalho pré-compilado)](../../build/reference/yc-create-precompiled-header-file.md) com o mesmo nome de arquivo de cabeçalho especificado no campo de **cabeçalho pré-compilado** . Uma causa comum desse problema trata do *stdafx. h* , já que, por padrão, *stdafx. cpp* inclui *stdafx. h* e não adiciona novos símbolos. Se outro arquivo de origem incluir *stdafx. h* com **/YC** e o arquivo. obj associado for processado antes de stdafx. obj, o vinculador irá lançar LNK4221.

::: moniker-end

Uma maneira de resolver esse problema é certificar-se de que, para cada cabeçalho pré-compilado, haja apenas um arquivo de origem que o inclua com **/YC**. Todos os outros arquivos de origem devem usar cabeçalhos pré-compilados. Para obter mais informações sobre como alterar essa configuração, consulte [/Yu (usar arquivo de cabeçalho pré-compilado)](../../build/reference/yu-use-precompiled-header-file.md).
