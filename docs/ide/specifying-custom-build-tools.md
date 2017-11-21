---
title: "Ferramentas de compilação especificando personalizado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCustomBuildTool.CustomBuildToolBeforeTargets
- VC.Project.VCCustomBuildTool.Outputs
- VC.Project.VCCustomBuildTool.Command
- VC.Project.VCCustomBuildTool.CommandLine
- VC.Project.VCCustomBuildTool.AdditionalDependencies
- VC.Project.VCCustomBuildTool.Message
- VC.Project.VCCustomBuildTool.CustomBuildToolAfterTargets
- VC.Project.VCCustomBuildTool.Description
- VC.Project.VCCustomBuildTool.AdditionalInputs
dev_langs: C++
helpviewer_keywords:
- build tools (C++), specifying
- custom build tools (C++), specifying
- builds (C++), custom build tools
ms.assetid: e5161946-8002-418d-991e-219e6a8586f5
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c65664e6c09028f1f15ded917a59ad013868f841
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="specifying-custom-build-tools"></a>Especificando ferramentas de build personalizadas
Um *ferramenta de compilação personalizada* fornece o sistema de compilação com as informações necessárias para criar arquivos de entrada específicos. Uma ferramenta de compilação personalizada especifica um comando a ser executado, uma lista de arquivos de entrada, uma lista dos arquivos de saída que são geradas pelo comando e uma descrição opcional da ferramenta.  
  
 Para obter informações gerais sobre as ferramentas de compilação personalizada e etapas de compilação personalizada, consulte [Noções básicas sobre etapas de compilação personalizadas e eventos de Build](../ide/understanding-custom-build-steps-and-build-events.md).  
  
### <a name="to-specify-a-custom-build-tool"></a>Para especificar uma ferramenta de compilação personalizada  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, consulte [configuração Visual C++ Project Properties](../ide/working-with-project-properties.md).  
  
2.  Clique em **propriedades de configuração** para habilitar o **configuração** caixa. No **configuração** , selecione a configuração para o qual você deseja especificar uma ferramenta de compilação personalizada.  
  
3.  Em **Solution Explorer**, selecione o arquivo de entrada para a ferramenta de compilação personalizada.  
  
     Se o **ferramenta de compilação personalizada** pasta não for exibida, a extensão de arquivo do arquivo selecionado está associada uma ferramenta padrão. Por exemplo, a ferramenta padrão para arquivos. c e. cpp é o compilador. Para substituir uma configuração de ferramenta padrão, no **propriedades de configuração** nó, no **geral** pasta, no **tipo de Item** propriedade, clique em **de compilação personalizada Ferramenta**. Clique em **aplicar** e **ferramenta de compilação personalizada** nó é exibido.  
  
4.  No **ferramenta de compilação personalizada** nó, no **geral** pasta, especifique as propriedades associadas ao personalizado ferramenta de compilação:  
  
    -   Em **dependências adicionais**, especificar os arquivos adicionais além para o qual a ferramenta de compilação personalizada é definida (o arquivo associado com a ferramenta de compilação personalizada implicitamente é considerado uma entrada para a ferramenta). Não é um requisito para uma ferramenta de compilação personalizada com arquivos de entrada adicionais. Se você tiver mais de uma entrada adicional, separe-os com ponto e vírgula.  
  
         Se um **dependências adicionais** data do arquivo for posterior ao arquivo de entrada, em seguida, a ferramenta de compilação personalizada é executada. Se todos os do **dependências adicionais** arquivos são mais antigos que o arquivo de entrada, e o arquivo de entrada é mais antigo que o **saídas** arquivo de propriedade, em seguida, a ferramenta de compilação personalizada não é executado.  
  
         Por exemplo, suponha que você tem uma ferramenta de compilação personalizada que usa MyInput.x como entrada e gera MyInput.cpp e MyInput.x inclui um arquivo de cabeçalho MyHeader.h. Você pode especificar MyHeader.h como uma dependência de entrada para MyInput.x, e o sistema de compilação criará MyInput.cpp quando ele está desatualizado em relação ao MyInput.x ou MyHeader.h.  
  
         Dependências de entrada também podem garantir que suas ferramentas de compilação personalizada são executados na ordem em que elas precisam. No exemplo anterior, suponha que MyHeader.h é, na verdade, a saída de uma ferramenta de compilação personalizada. Como uma dependência de MyInput.x MyHeader.h, o sistema de compilação criará primeiro Myheader.h antes de executar a ferramenta de compilação personalizada em MyInput.x.  
  
    -   Em **linha de comando**, especifique um comando como se foram especificá-lo no prompt de comando. Especifique um comando válido ou um arquivo em lote, e qualquer entrada necessária ou arquivos de saída. Especifique o **chamar** comando antes do nome de um arquivo em lotes para garantir que todos os comandos subsequentes serão executados em lote.  
  
         Vários arquivos de entrada e saídos podem ser especificados de maneira simbólica com macros do MSBuild. [!INCLUDE[crabout](../build/reference/includes/crabout_md.md)]especificar o local dos arquivos ou os nomes dos conjuntos de arquivos, consulte [comuns Macros para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).  
  
         Como o caractere '%' é reservado pelo MSBuild, se você especificar uma variável de ambiente substitua cada  **%**  escape de caractere com o **% 25** sequência de escape hexadecimal. Por exemplo, substitua **% WINDIR %** com **25WINDIR % 25**. MSBuild substitui cada **% 25** de sequência com a  **%**  caracteres antes de acessar a variável de ambiente.  
  
    -   Em **descrição**, digite uma mensagem descritiva sobre essa ferramenta de compilação personalizada. A mensagem será impressa para o **saída** janela quando o sistema de compilação processa esta ferramenta.  
  
    -   Em **saídas**, especifique o nome do arquivo de saída. Essa é uma entrada necessária; sem um valor para essa propriedade, a ferramenta de compilação personalizada não será executada. Se uma ferramenta de compilação personalizada tiver mais de uma saída, separe os nomes de arquivo com um ponto e vírgula.  
  
         O nome do arquivo de saída deve ser o mesmo que ele seja especificado no **linha de comando** propriedade. O sistema de compilação do projeto será procurar o arquivo e verifique a data. Se o arquivo de saída for mais recente que o arquivo de entrada ou se o arquivo de saída não for encontrado, a ferramenta de compilação personalizada será executada. Se todos os do **dependências adicionais** arquivos são mais antigos que o arquivo de entrada e o arquivo de entrada é mais antigo que o arquivo especificado no **saídas** propriedade, a ferramenta de compilação personalizada não é executada.  
  
 Se você deseja que o sistema de compilação para operar em um arquivo de saída gerado pela ferramenta de compilação personalizada, adicione manualmente-lo ao projeto. A ferramenta de compilação personalizada atualizará o arquivo durante a compilação.  
  
## <a name="example"></a>Exemplo  
 Suponha que você deseja incluir em seu projeto de um arquivo chamado parser.l. Você deseja que um analisador léxico para processar parser.l para produzir um arquivo de c que tem o mesmo nome base (parser.c).  
  
 Primeiro, adicione parser.l e parser.c ao projeto. Se os arquivos ainda não existir, basta adicionar uma referência para os arquivos. Criar uma ferramenta de compilação personalizada para parser.l e digite o seguinte no **comandos** propriedade:  
  
```  
lexer %(FullPath) .\%(Filename).c  
```  
  
 Este comando executar o analisador lexical em parser.l e parser.c para o diretório do projeto de saída.  
  
 No **saídas** propriedade, digite o seguinte:  
  
```  
.\%(Filename).c  
```  
  
 Quando você compila o projeto, o sistema de compilação compara os carimbos de hora de parser.l e parser.c. Se parser.l for mais recente, ou se parser.c não existir, o sistema de compilação é executado o valor da **linha de comando** propriedade trazer parser.c atualizado. Como parser.c também foi adicionado ao projeto, o sistema de compilação, em seguida, compila parser.c.  
  
## <a name="see-also"></a>Consulte também  
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Solucionando problemas de personalização de compilação](../ide/troubleshooting-build-customizations.md)