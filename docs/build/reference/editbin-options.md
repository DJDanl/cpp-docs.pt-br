---
title: "Opções EDITBIN | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: editbin
dev_langs: C++
helpviewer_keywords: EDITBIN program, options
ms.assetid: 2da9f88e-cbab-4d64-bb66-ef700535230f
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2658b2ca23ef34b63e0788791f3fb528107e1efd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="editbin-options"></a>Opções EDITBIN
Você pode usar EDITBIN para modificar arquivos de objeto, arquivos executáveis e bibliotecas de vínculo dinâmico (DLLs). Opções especificam as alterações que EDITBIN faz.  
  
 Uma opção consiste em um especificador de opção, que é um traço (-) ou uma barra invertida (/), seguido do nome da opção. Nomes de opção não podem ser abreviados. Algumas opções usam argumentos que são especificados após dois-pontos (:). Nenhum tabulações ou espaços são permitidas dentro de uma especificação de opção. Use um ou mais espaços ou guias para separar as especificações de opção na linha de comando. Os nomes de opções e seus argumentos de palavra-chave ou argumentos de nome de arquivo não diferenciam maiusculas de minúsculas. Por exemplo, - bind e /BIND. têm o mesmo significado.  
  
 EDITBIN tem as seguintes opções:  
  
|Opção|Finalidade|  
|------------|-------------|  
|[/ALLOWBIND](../../build/reference/allowbind.md)|Especifica se uma DLL pode ser associada.|  
|[/ALLOWISOLATION](../../build/reference/allowisolation.md)|Especifica o comportamento de pesquisa de manifesto do arquivo executável ou de DLL.|  
|[/APPCONTAINER](../../build/reference/appcontainer.md)|Especifica se o aplicativo deve ser executado em um AppContainer — por exemplo, um [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativo.|  
|[/ LIGAÇÃO](../../build/reference/bind.md)|Define os endereços para os pontos de entrada nos objetos para acelerar o tempo de carga especificados.|  
|[/DYNAMICBASE](../../build/reference/dynamicbase.md)|Especifica se a DLL ou imagem executável pode ser baseada aleatoriamente de novo no tempo de carregamento usando aleatória de layout de espaço de endereço (ASLR).|  
|[/ ERRORREPORT](../../build/reference/errorreport-editbin-exe.md)|Relatórios de erros internos à Microsoft.|  
|[/ PILHA](../../build/reference/heap.md)|Define o tamanho da pilha da imagem executável em bytes.|  
|[/HIGHENTROPYVA](../../build/reference/highentropyva.md)|Especifica se a DLL ou imagem executável dá suporte à alta entropia endereço (64 bits) aleatorização do espaço (ASLR).|  
|[/INTEGRITYCHECK](../../build/reference/integritycheck.md)|Especifica se é necessário verificar a assinatura digital no tempo de carregamento.|  
|[/LARGEADDRESSAWARE](../../build/reference/largeaddressaware.md)|Especifica se o objeto der suporte a endereços maiores que dois gigabytes.|  
|[/NOLOGO](../../build/reference/nologo-editbin.md)|Suprime a faixa de inicialização EDITBIN.|  
|[/NXCOMPAT](../../build/reference/nxcompat.md)|Especifica se a imagem executável é compatível com Windows Data Execution Prevention.|  
|[/ REBASE](../../build/reference/rebase.md)|Define os endereços de base para os objetos especificados.|  
|[/ VERSÃO](../../build/reference/release.md)|Define a soma de verificação no cabeçalho.|  
|[/ SEÇÃO](../../build/reference/section-editbin.md)|Substitui os atributos de uma seção.|  
|[/ PILHA](../../build/reference/stack.md)|Define o tamanho da pilha da imagem executável em bytes.|  
|[/ O SUBSISTEMA](../../build/reference/subsystem.md)|Especifica o ambiente de execução.|  
|[/ SWAPRUN](../../build/reference/swaprun.md)|Especifica que a imagem executável deve ser copiada para o arquivo de permuta e, em seguida, execute a partir daí.|  
|[/ TSAWARE](../../build/reference/tsaware.md)|Especifica que o aplicativo foi projetado para ser executado em um ambiente multiusuário.|  
|[/ VERSÃO](../../build/reference/version.md)|Define o número de versão no cabeçalho.|  
  
## <a name="see-also"></a>Consulte também  
 [Ferramentas de compilação do C/C++](../../build/reference/c-cpp-build-tools.md)   
 [Referência de EDITBIN](../../build/reference/editbin-reference.md)