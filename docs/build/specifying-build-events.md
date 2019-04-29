---
title: Especificando eventos de compilação
ms.date: 12/28/2017
f1_keywords:
- VC.Project.IVCEventTool.CommandLine
- VC.Project.IVCEventTool.ExcludedFromBuild
- VC.Project.IVCEventTool.Description
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
ms.openlocfilehash: c8097e013f934c45b8e3860b8377bdb2bdb9d9a0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315229"
---
# <a name="specifying-build-events"></a>Especificando eventos de build

Use eventos de build para especificar comandos que são executados antes do início do build, antes do processo de vínculo ou após a conclusão do build.

Eventos de build são executados somente se o build atingir com êxito esses pontos no processo de build. Se ocorrer um erro no build, o evento *pós-build* não ocorrerá; se o erro ocorrer antes da fase de vinculação, os eventos *pré-vínculo* e *pós-build* não ocorrerão. Além disso, se nenhum arquivo precisar ser vinculado, o evento *pré-vínculo* não ocorrerá. O evento *pré-vínculo* também não está disponível em projetos que não contêm uma etapa de vínculo.

Se nenhum arquivo precisar ser compilado, não ocorrerá nenhum evento de build.

Para obter informações gerais sobre eventos de build, confira [Noções básicas sobre eventos e etapas de build personalizadas](understanding-custom-build-steps-and-build-events.md).

### <a name="to-specify-a-build-event"></a>Para especificar um evento de build

1. No **Gerenciador de Soluções**, selecione o projeto para o qual deseja especificar o evento de build.

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter mais informações, consulte [propriedades de compilador e de build definida C++ no Visual Studio](working-with-project-properties.md).

1. Na pasta **Eventos de Build**, selecione uma página de propriedades do evento de build.

1. Especifique as propriedades associadas ao evento de build:

   - Em **Linha de Comando**, especifique um comando como se o estivesse especificando no prompt de comando. Especifique um comando ou arquivo em lotes válido e os arquivos de entrada ou de saída necessários. Especifique o comando em lote **call** antes do nome de um arquivo em lotes para assegurar que todos os comandos seguintes sejam executados.

      Vários arquivos de entrada e de saída podem ser especificados simbolicamente com macros do MSBuild. Para obter informações sobre como especificar o local dos arquivos ou os nomes dos conjuntos de arquivos, consulte [macros comuns para compilar comandos e propriedades](reference/common-macros-for-build-commands-and-properties.md).

      Como o caractere '%' é reservado pelo MSBuild, se você especificar uma variável de ambiente, substitua cada caractere de escape **%** pela sequência de escape hexadecimal **%25**. Por exemplo, substitua **%WINDIR%** por **%25WINDIR%25**. O MSBuild substitui cada sequência **%25** pelo caractere **%** antes de acessar a variável de ambiente.

   - Em **Descrição**, digite uma descrição para esse evento. A descrição será impressa na janela de **Saída** quando esse evento ocorrer.

   - Em **Excluído do Build**, especifique **Sim** se não desejar que o evento seja executado.

## <a name="see-also"></a>Consulte também

[Noções básicas sobre etapas e eventos compilação personalizada](understanding-custom-build-steps-and-build-events.md)<br>
[Macros comuns para comandos e propriedades de build](reference/common-macros-for-build-commands-and-properties.md)<br>
[Solucionando problemas de personalização de compilação](troubleshooting-build-customizations.md)
