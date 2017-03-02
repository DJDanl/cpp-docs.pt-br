---
title: Ferramentas de vinculador LNK1104 erro | Documentos do Microsoft
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bf097a5bd6eb63a21d1a6feebd87e5836b0db100
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk1104"></a>Erro das Ferramentas de Vinculador LNK1104
não é possível abrir o arquivo 'filename'  
  
 A ferramenta não pôde abrir o arquivo especificado.  
  
 Para corrigir verificando as possíveis causas:  
  
-   Espaço insuficiente em disco.  
  
-   Arquivo inexistente.  
  
-   Ao especificar bibliotecas na caixa de diálogo de páginas de propriedades do projeto, os nomes de bibliotecas devem ser separados por espaços (e não vírgulas).  
  
-   Caminho ou nome de arquivo incorreto.  
  
-   Especificação de unidade inválida.  
  
-   Permissões de arquivo suficientes.  
  
-   Caminho para `filename` expande a mais de 260 caracteres.  
  
-   Se o arquivo fornecido é denominado `LNKn`, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir ou mais de um diretório foi especificado para a variável de ambiente TMP. Apenas um caminho deve ser especificado para a variável de ambiente TMP.  
  
-   Se a mensagem de erro ocorre para um nome de biblioteca e você recentemente portado o arquivo .mak de um sistema de desenvolvimento Microsoft Visual C++ anterior, a biblioteca pode não ser válida. Certifique-se de que a biblioteca ainda existe nessa circunstância.  
  
-   Outro programa pode ter o arquivo aberto e o vinculador não pode gravar nele.  
  
-   Variável de ambiente LIB incorreto. Para obter informações sobre como atualizar a variável de ambiente LIB, consulte [página de propriedade de diretórios VC + +](../../ide/vcpp-directories-property-page.md) . Verifique se todos os diretórios com as bibliotecas que necessárias estão listados aqui.  
  
 O vinculador usa arquivos temporários em vários casos. Mesmo que você tenha espaço em disco suficiente, um link muito grande pode depauperam ou fragmento de espaço em disco disponível. Considere essa opção:  
  
-   Use [/OPÇ (otimizações)](../../build/reference/opt-optimizations.md); fazer eliminação comdat transitiva lê todos os arquivos de objeto várias vezes.
