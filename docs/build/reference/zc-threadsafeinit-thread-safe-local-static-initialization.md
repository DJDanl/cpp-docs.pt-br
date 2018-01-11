---
title: "/ZC:threadSafeInit (thread-safe inicialização estática de Local) | Microsoft Docs"
ms.custom: 
ms.date: 12/13/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- threadSafeInit
- /Zc:threadSafeInit
dev_langs: C++
helpviewer_keywords:
- -Zc compiler options (C++)
- threadSafeInit
- Thread-safe Local Static Initialization
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: a0fc4b34-2cf0-45a7-a642-b8afc4ca19f2
caps.latest.revision: "1"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a03f3ea67c9ecabd6fa68d653a3e1812fb0266cc
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcthreadsafeinit-thread-safe-local-static-initialization"></a>/ZC:threadSafeInit (thread-safe inicialização estática de Local)  
O `/Zc:threadSafeInit` opção de compilador informa ao compilador para inicializar variáveis locais estáticas (escopo da função) em uma forma thread-safe, eliminando a necessidade de sincronização manual. Somente a inicialização é thread-safe. Uso e a modificação de variáveis locais estáticas por vários threads ainda deverão ser manualmente sincronizados. Essa opção está disponível a partir do Visual Studio 2015. Por padrão, o Visual Studio permite que essa opção.  
  
## <a name="syntax"></a>Sintaxe  
  
`/Zc:threadSafeInit`[`-`]  
  
## <a name="remarks"></a>Comentários  
  
11 C++ padrão, variáveis de escopo de bloco com estática ou duração do armazenamento de thread deve ser inicializada do zero antes de qualquer outra inicialização ocorre. A inicialização ocorre quando o controle passa pela primeira vez por meio da declaração da variável. Se uma exceção é lançada durante a inicialização, a variável é considerada não inicializada e inicialização é tentada novamente o próximo controle de tempo passa por meio da declaração. Se o controle entra a declaração simultaneamente com a inicialização, os blocos de execução simultânea durante a inicialização é concluída. O comportamento será indefinido se controle reinserido recursivamente a declaração durante a inicialização. Por padrão, o Visual Studio a partir do Visual Studio 2015 implementa esse comportamento padrão. Esse comportamento pode ser especificado explicitamente, definindo o `/Zc:threadSafeInit` opção de compilador.  
  
Inicialização de thread seguro de variáveis locais estáticas depende do código implementado na biblioteca de tempo de execução do C Universal (UCRT). Para evitar a assumir uma dependência da UCRT, ou para preservar o comportamento de inicialização de thread seguro de versões do Visual Studio antes do Visual Studio 2015, use o `/Zc:threadSafeInit-` opção. Se você souber que segurança de thread não é necessária, use esta opção para gerar código ligeiramente menor, mais rápido em torno de declarações locais estáticos.  
  
Variáveis locais estáticas de thread-safe usam armazenamento local de thread (TLS) internamente para fornecer a execução eficiente estático já foi inicializada. A implementação desse recurso depende de funções de suporte do sistema operacional Windows no Windows Vista e sistemas operacionais posteriores. Windows XP, Windows Server 2003 e sistemas operacionais mais antigos não possuem esse suporte, para que eles não obter uma vantagem de eficiência. Estes sistemas operacionais também têm um limite inferior no número de seções TLS que pode ser carregado. Excedendo os TLS limite de seção pode causar uma falha. Se este é um problema no seu código, especialmente no código que deve ser executado em sistemas operacionais mais antigos, use `/Zc:threadSafeInit-` para desabilitar o código de inicialização do thread-safe.  
  
Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).
2.  Do **configurações** menu suspenso, escolha **todas as configurações de**.
3.  Selecione o **propriedades de configuração**, **C/C++**, **linha de comando** página de propriedades.
4.  Modificar o **opções adicionais** propriedade incluir `/Zc:threadSafeInit` ou `/Zc:threadSafeInit-` e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também  
[Opções do Compilador](../../build/reference/compiler-options.md)  
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
[/ZC (conformidade)](../../build/reference/zc-conformance.md)  
