---
title: Especificando eventos de Build | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.IVCEventTool.CommandLine
- VC.Project.IVCEventTool.ExcludedFromBuild
- VC.Project.IVCEventTool.Description
dev_langs: C++
helpviewer_keywords:
- Pre-Link event
- build events [C++], specifying
- custom build steps [C++], build events
- builds [C++], events
- events [C++], build
- builds [C++], customizing C++
- build events [C++]
- post-build events
ms.assetid: 788a6c18-2dbe-4a49-8cd6-86c1ad7a95cc
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 43f12e28487a4e162a88eaf0881ac9e50391e1f4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="specifying-build-events"></a>Especificando eventos de build
Você pode usar eventos de compilação para especificar comandos executados antes do início da compilação, antes que o processo de link, ou após a conclusão da compilação.  
  
 Eventos de build são executados somente se o build atingir com êxito esses pontos no processo de build. Se ocorrer um erro na compilação, o *pós-compilação* evento não ocorrerá; se o erro ocorrer antes da fase de vinculação, nem o *pré-vínculo* nem o *pós-compilação* será de evento ocorra. Além disso, se nenhum arquivo precisa ser vinculado, o *pré-vínculo* evento não ocorrerá. O *pré-vínculo* evento também não está disponível nos projetos que não contêm uma etapa de link.  
  
 Se nenhum arquivo precisa ser criado, não há eventos de compilação ocorrerá.  
  
 Para obter informações gerais sobre eventos de build, consulte [etapas de compilação personalizada de Noções básicas sobre e eventos de Build](../ide/understanding-custom-build-steps-and-build-events.md).  
  
### <a name="to-specify-a-build-event"></a>Para especificar um evento de build  
  
1.  No **Gerenciador de Soluções**, selecione o projeto para o qual deseja especificar o evento de build.  
  
2.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).  
  
3.  No **eventos de Build** pasta, selecione uma página de propriedades de evento de compilação.  
  
4.  Especifique as propriedades associadas ao evento de compilação:  
  
    -   Em **linha de comando**, especifique um comando como se foram especificá-lo no prompt de comando. Especifique um comando válido ou um arquivo em lote, e qualquer entrada necessária ou arquivos de saída. Especifique o **chamar** comando antes do nome de um arquivo em lotes para garantir que todos os comandos subsequentes serão executados em lote.  
  
         Vários arquivos de entrada e saídos podem ser especificados de maneira simbólica com macros do MSBuild. [!INCLUDE[crabout](../build/reference/includes/crabout_md.md)]especificar o local dos arquivos ou os nomes dos conjuntos de arquivos, consulte [comuns Macros para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).  
  
         Como o caractere '%' é reservado pelo MSBuild, se você especificar uma variável de ambiente substitua cada  **%**  escape de caractere com o **% 25** sequência de escape hexadecimal. Por exemplo, substitua **% WINDIR %** com **25WINDIR % 25**. MSBuild substitui cada **% 25** de sequência com a  **%**  caracteres antes de acessar a variável de ambiente.  
  
    -   Em **descrição**, digite uma descrição para esse evento. A descrição será impressa para o **saída** janela quando esse evento ocorrer.  
  
    -   Em **excluído da compilação**, especifique **Sim** se você não quiser que o evento seja executado.  
  
## <a name="see-also"></a>Consulte também  
 [Noções básicas sobre etapas de compilação personalizada e eventos de Build](../ide/understanding-custom-build-steps-and-build-events.md)   
 [Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)   
 [Solucionando problemas de personalização de compilação](../ide/troubleshooting-build-customizations.md)