---
title: Especificando eventos de Build | Microsoft Docs
ms.custom: ''
ms.date: 12/28/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.IVCEventTool.CommandLine
- VC.Project.IVCEventTool.ExcludedFromBuild
- VC.Project.IVCEventTool.Description
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5940f0d6efaec402a4a85ed659f42d7eab1bf91d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="specifying-build-events"></a>Especificando eventos de build

Você pode usar eventos de compilação para especificar comandos executados antes do início da compilação, antes que o processo de link, ou após a conclusão da compilação.

Eventos de build são executados somente se o build atingir com êxito esses pontos no processo de build. Se ocorrer um erro na compilação, o *pós-compilação* evento não ocorrerá; se o erro ocorrer antes da fase de vinculação, nem o *pré-vínculo* nem o *pós-compilação* evento ocorre. Além disso, se nenhum arquivo precisa ser vinculado, o *pré-vínculo* evento não ocorrerá. O *pré-vínculo* evento também não está disponível nos projetos que não contêm uma etapa de link.

Se nenhum arquivo precisa ser criado, não ocorre nenhum evento de compilação.

Para obter informações gerais sobre eventos de build, consulte [etapas de compilação personalizada de Noções básicas sobre e eventos de Build](../ide/understanding-custom-build-steps-and-build-events.md).

### <a name="to-specify-a-build-event"></a>Para especificar um evento de build

1. No **Gerenciador de Soluções**, selecione o projeto para o qual deseja especificar o evento de build.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, consulte [trabalhar com propriedades do projeto](../ide/working-with-project-properties.md).

1. No **eventos de Build** pasta, selecione uma página de propriedades de evento de compilação.

1. Especifique as propriedades associadas ao evento de compilação:

   - Em **linha de comando**, especifique um comando como se foram especificá-lo no prompt de comando. Especifique um comando válido ou um arquivo em lote, e qualquer entrada necessária ou arquivos de saída. Especifique o **chamar** comando antes do nome de um arquivo em lotes para garantir que todos os comandos subsequentes serão executados em lote.

      Vários arquivos de entrada e saídos podem ser especificados de maneira simbólica com macros do MSBuild. Para obter informações sobre como especificar o local dos arquivos ou os nomes dos conjuntos de arquivos, consulte [comuns Macros para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md).

      Como o caractere '%' é reservado pelo MSBuild, se você especificar uma variável de ambiente substitua cada **%** escape de caractere com o **% 25** sequência de escape hexadecimal. Por exemplo, substitua **% WINDIR %** com **25WINDIR % 25**. MSBuild substitui cada **% 25** de sequência com a **%** caracteres antes de acessar a variável de ambiente.

   - Em **descrição**, digite uma descrição para esse evento. A descrição é impressa a **saída** janela quando esse evento ocorrer.

   - Em **excluído da compilação**, especifique **Sim** se você não quiser que o evento seja executado.

## <a name="see-also"></a>Consulte também

[Noções básicas sobre etapas e eventos compilação personalizada](../ide/understanding-custom-build-steps-and-build-events.md)  
[Macros comuns para compilar comandos e propriedades](../ide/common-macros-for-build-commands-and-properties.md)  
[Solucionando problemas de personalização de compilação](../ide/troubleshooting-build-customizations.md)  
