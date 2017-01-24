---
title: "Erro das Ferramentas de Vinculador LNK1104 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "LNK1104"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "LNK1104"
ms.assetid: 9ca6f929-0efc-4055-8354-3cf5b4e636dc
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro das Ferramentas de Vinculador LNK1104
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

não é possível abrir o arquivo 'filename'  
  
 A ferramenta não pôde abrir o arquivo especificado.  
  
 Para corrigir verificando as possíveis causas:  
  
-   Espaço insuficiente em disco.  
  
-   Arquivo não existe.  
  
-   Ao especificar bibliotecas na caixa de diálogo de páginas de propriedades do projeto, os nomes de bibliotecas devem ser separados por espaços \(e não vírgulas\).  
  
-   Caminho ou nome de arquivo incorreto.  
  
-   Especificação de unidade inválida.  
  
-   Permissões de arquivo suficientes.  
  
-   Caminho para `filename` expande a mais de 260 caracteres.  
  
-   Se o arquivo fornecido é denominado `LNKn`, que é um nome de arquivo gerado pelo vinculador para um arquivo temporário, o diretório especificado na variável de ambiente TMP pode não existir ou mais de um diretório foi especificado para a variável de ambiente TMP. Apenas um caminho deve ser especificado para a variável de ambiente TMP.  
  
-   Se a mensagem de erro ocorre para um nome de biblioteca e você recentemente portado o arquivo .mak de um sistema de desenvolvimento Microsoft Visual C\+\+ anterior, a biblioteca pode não ser válida. Certifique\-se de que a biblioteca ainda existe nessa circunstância.  
  
-   Outro programa pode ter o arquivo aberto e o vinculador não pode gravar nele.  
  
-   Variável de ambiente LIB incorreto. Para obter informações sobre como atualizar a variável de ambiente LIB, consulte [Página de propriedade dos diretórios do VC\+\+](../../ide/vcpp-directories-property-page.md) . Verifique se todos os diretórios com as bibliotecas que necessárias estão listados aqui.  
  
 O vinculador usa arquivos temporários em vários casos. Mesmo que você tenha espaço em disco suficiente, um link muito grande pode depauperam ou fragmento de espaço em disco disponível. Considere essa opção:  
  
-   Use [\/OPT \(Otimizações\)](../../build/reference/opt-optimizations.md); fazer eliminação comdat transitiva lê todos os arquivos de objeto várias vezes.