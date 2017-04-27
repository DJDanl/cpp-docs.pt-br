---
title: Ferramentas de vinculador LNK1104 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK1104
dev_langs:
- C++
helpviewer_keywords:
- LNK1104
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 4bac7b2942f9d72674b8092dc7bf64174dd3c349
ms.openlocfilehash: 7fce9c60da4bceafb9ee81231a8630acb4397d83
ms.lasthandoff: 04/24/2017

---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104
não é possível abrir o arquivo '*filename*'  
  
O vinculador não foi possível abrir o arquivo especificado.  
  
Para corrigir esse erro, verifique as possíveis causas:  
  
-   O arquivo *filename* não existe. Se seu projeto depende de outro projeto para gerar esse arquivo, certifique-se de que suas dependências do projeto estão definidas corretamente.  
  
-   Ao especificar bibliotecas na caixa de diálogo páginas de propriedades do projeto, os nomes de biblioteca devem ser separados por espaços, vírgulas não.  
  
-   O nome do arquivo ou o caminho especificado na linha de comando está incorreto ou o caminho tem uma especificação de unidade inválida. Verifique a ortografia e verifique se o nome do arquivo e o local. Se você estiver criando um projeto que foi copiado de outro computador, verifique os caminhos no [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) e atualizá-las se necessário.  
  
-   As bibliotecas para a configuração de projeto ou um conjunto de ferramentas da plataforma não estão instaladas. Verifique se o conjunto de ferramentas de plataforma e o SDK do Windows especificado nas páginas de propriedade para o seu projeto está instalado e inclui o conjunto de ferramentas e bibliotecas necessárias para as configurações. Existem configurações separadas para as configurações de depuração e de varejo, portanto se uma criar funciona, mas a outra causa um erro, verifique se as configurações estão corretas e as ferramentas necessárias estão instaladas para ambas as configurações.  
  
-   Você não tem espaço em disco suficiente. Não é incomum para o vinculador para consumir muito espaço em disco temporário durante um link.  
  
-   Você tem permissões de arquivo suficientes para acessar *filename*.  
  
-   O caminho para *filename* expande a mais do que 260 caracteres. Alterar os nomes ou reorganizar a estrutura de diretório, se necessário para encurtar caminhos para os arquivos necessários.  
  
-   Se o *filename* chamado LNK*n*, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir ou pode ser especificado mais de um diretório para a variável de ambiente TMP. Apenas um caminho deve ser especificado para a variável de ambiente TMP.  
  
-   Se a mensagem de erro ocorre para um nome de biblioteca, e você recentemente movido o arquivo .mak de um sistema de desenvolvimento Microsoft Visual C++ anterior, a biblioteca pode não ser mais válida. Certifique-se de que o nome da biblioteca está correto e ainda existe no local especificado, ou atualize o caminho de biblioteca para apontar para o novo local.  
  
-   Outro programa pode ter o arquivo aberto e não é possível gravar o vinculador a ele. Programas antivírus geralmente bloqueiam temporariamente o acesso a arquivos recém-criados. Tente excluir seus diretórios de compilação de projeto do scanner antivírus.  
  
-   Você tem uma variável de ambiente LIB incorretova. Para obter informações sobre como atualizar a variável de ambiente LIB, consulte [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md). Verifique se todos os diretórios com bibliotecas que necessárias estão listados aqui.  
  
-   O vinculador usa arquivos temporários em vários casos. Mesmo se você tiver espaço suficiente em disco, um link muito grande pode depauperam ou fragmento de espaço em disco disponível. Considere o uso de [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md) opção; fazendo leituras de eliminação de comdat transitiva todos os arquivos de objeto várias vezes.
