---
title: CL invoca o vinculador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cl
dev_langs:
- C++
helpviewer_keywords:
- compiling source code [C++], without linking
- invoking linker from the compiler
- LINK tool [C++], invoking from CL compiler
- cl.exe compiler [C++], compiling without linking
- cl.exe compiler [C++], controlling linker
ms.assetid: eae47ef7-09eb-40c9-b318-7c714cd452fc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 32a3bdd1e227b894ca5a32ddfaa8c46a478a19f7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cl-invokes-the-linker"></a>O CL invoca o vinculador
Automaticamente o CL invoca o vinculador após a compilação, a menos que a opção /c é usada. CL passa para o vinculador os nomes dos arquivos. obj criados durante a compilação e os nomes de todos os outros arquivos especificados na linha de comando. O vinculador usa as opções listadas na variável de ambiente LINK. Você pode usar a opção /link para especificar opções de vinculador na linha de comando CL. Opções que se seguem a opção /link substituem aquelas na variável de ambiente LINK. As opções na tabela a seguir suprimir a vinculação.  
  
|Opção|Descrição|  
|------------|-----------------|  
|/c|Compilar sem vinculação|  
|/ / E, /EP, P|Pré-processar sem compilar ou vincular|  
|/Zg|Gerar protótipos de função|  
|/Zs|Verificar sintaxe|  
  
 Para obter mais detalhes sobre como vincular, consulte [opções do vinculador](../../build/reference/linker-options.md).  
  
## <a name="example"></a>Exemplo  
 Suponha que você estiver compilando C três arquivos de origem: MAIN.c, MOD1.c e MOD2.c. Cada arquivo inclui uma chamada para uma função definida em um arquivo diferente:  
  
-   MAIN.c chama a função `func1` MOD1.c e a função `func2` em MOD2.c.  
  
-   MOD1.c chama as funções de biblioteca padrão `printf_s` e `scanf_s`.  
  
-   MOD2.c chama funções gráficas denominadas `myline` e `mycircle`, que é definido em uma biblioteca denominada MYGRAPH.lib.  
  
 Para criar este programa, compile com a seguinte linha de comando:  
  
```  
CL MAIN.c MOD1.C MOD2.C MYGRAPH.lib  
```  
  
 CL primeiro compila os arquivos de origem C e cria os arquivos de objeto MAIN.obj, MOD1.obj e MOD2.obj. O compilador coloca o nome da biblioteca padrão em cada arquivo. obj. Para obter mais detalhes, consulte [usar a biblioteca de tempo de execução](../../build/reference/md-mt-ld-use-run-time-library.md).  
  
 CL passa os nomes dos arquivos. obj, juntamente com o nome MYGRAPH.lib, para o vinculador. O vinculador resolve as referências externas, como se segue:  
  
1.  Em MAIN.obj, a referência ao `func1` é resolvido usando a definição da MOD1.obj; a referência ao `func2` é resolvido usando a definição da MOD2.obj.  
  
2.  Em MOD1.obj, as referências a `printf_s` e `scanf_s` são resolvidos usando as definições na biblioteca que localiza o vinculador chamada dentro de MOD1.obj.  
  
3.  Em MOD2.obj, as referências a `myline` e `mycircle` são resolvidos usando as definições em MYGRAPH.lib.  
  
## <a name="see-also"></a>Consulte também  
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)