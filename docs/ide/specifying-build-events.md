---
title: "Especificando eventos de compila&#231;&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "VC.Project.IVCEventTool.CommandLine"
  - "VC.Project.IVCEventTool.ExcludedFromBuild"
  - "VC.Project.IVCEventTool.Description"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "eventos de compilação [C++]"
  - "eventos de compilação [C++], especificando"
  - "compilações [C++], personalizando C++"
  - "compilações [C++], eventos"
  - "etapas de compilação personalizada [C++], compilar eventos"
  - "eventos [C++], compilar"
  - "pós-eventos de compilação"
  - "evento Pré-link"
ms.assetid: 788a6c18-2dbe-4a49-8cd6-86c1ad7a95cc
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Especificando eventos de compila&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar eventos de compilação para especificar os comandos que executa antes que a construção, antes do processo de link, ou após a conclusão da compilação.  
  
 Criar eventos são executados somente se a compilação com êxito atingir esses pontos em o processo de criação.  Se ocorrer um erro na construção, o evento *pós\-compilação* não ocorrerá; se o erro ocorrer antes que a fase de vinculação, nem o evento *pré\-vinculação* ou *pós\-compilação* ocorrem.  Além disso, se nenhum arquivo precisa ser vinculado, o evento *do vínculo* não ocorrerá.  O evento *do vínculo* não também está disponível nos projetos que não contêm uma etapa do link.  
  
 Se nenhum arquivo precisa ser criado, nenhum evento de compilação ocorrerá.  
  
 Para obter informações gerais sobre eventos de compilação, consulte [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md).  
  
### Para especificar um evento compilação  
  
1.  No **Solution Explorer**, selecione o projeto para o qual você deseja especificar o evento de compilação.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter mais informações, consulte [Trabalhando com propriedades do projeto](../ide/working-with-project-properties.md).  
  
3.  Na pasta de **Compilar Eventos** , selecione uma página de propriedades de evento de compilação.  
  
4.  Especifique as propriedades associadas ao evento de construção:  
  
    -   Em **Linha de Comando**, especifique um comando como se você especificou no prompt de comando.  Especifique um comando ou um arquivo em lotes válido, e qualquer entrada ou de saída arquivos necessários.  Especifique o comando do lote de **call** antes do nome de um arquivo em lotes garantir que todos os comandos subsequentes serão executados.  
  
         A vários arquivos de entrada e de saída podem ser especificados simbolicamente com macros de MSBuild.  [!INCLUDE[crabout](../Token/crabout_md.md)] que especificam o local dos arquivos, ou os nomes dos conjuntos de arquivos, consulte [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).  
  
         Como o caractere “%” é permitido por MSBuild, se você especificar uma variável de ambiente substituir cada caractere de escape de **%** com a sequência de escape hexadecimal de **%25** .  Por exemplo, substitua **%WINDIR%** com **%25WINDIR%25**.  MSBuild substitui cada sequência de **%25** com o caractere de **%** antes de acessar a variável de ambiente.  
  
    -   Em **Descrição**, digite uma descrição para esse evento.  A descrição será impressa à janela de **Saída** quando esse evento ocorre.  
  
    -   Em **Excluído da Compilação**, especifique **Sim** se você não quiser que o evento a ser executada.  
  
## Consulte também  
 [Noções básicas de etapas e eventos de compilação personalizados](../ide/understanding-custom-build-steps-and-build-events.md)   
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Solucionando problemas de personalizações da compilação](../ide/troubleshooting-build-customizations.md)