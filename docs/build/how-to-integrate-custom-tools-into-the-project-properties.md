---
title: 'Como: integrar ferramentas personalizar as propriedades do projeto | Microsoft Docs'
ms.custom: ''
ms.date: 04/27/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
f1_keywords:
- msbuild.cpp.howto.integratecustomtools
dev_langs:
- C++
helpviewer_keywords:
- 'msbuild (c++), howto: integrate custom tools'
ms.assetid: f32d91a4-44e9-4de3-aa9a-1c7f709ad2ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 00482aa2b4b700d15e46d0741e76dd17afc28419
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368896"
---
# <a name="how-to-integrate-custom-tools-into-the-project-properties"></a>Como integrar ferramentas personalizar a propriedades de projeto
Você pode adicionar opções de ferramenta personalizada para o Visual Studio **páginas de propriedade** janela criando um arquivo de esquema XML subjacente.  
  
 O **propriedades de configuração** seção o **páginas de propriedade** janela exibe os grupos de configuração que são conhecidos como *regras*. Cada regra contém as configurações para uma ferramenta ou um grupo de recursos. Por exemplo, o **vinculador** regra contém as configurações para a ferramenta do vinculador. As configurações em uma regra podem ser subdivididas em *categorias*.  
  
 Este documento explica como criar um arquivo em um diretório de conjunto que contém propriedades de sua ferramenta personalizada para que as propriedades são carregadas quando o Visual Studio inicia. Para obter informações sobre como modificar o arquivo, consulte [plataforma Extensibilty parte 2](http://go.microsoft.com/fwlink/p/?linkid=191489) no blog da equipe de projeto do Visual Studio.  
  
### <a name="to-add-or-change-project-properties"></a>Para adicionar ou alterar propriedades do projeto  
  
1.  No editor de XML, crie um arquivo XML.  
  
2.  Salve o arquivo em que o Visual Studio de 2017 `VCTargets\1033` pasta. Você terá um caminho diferente para cada edição do Visual Studio de 2017 que está instalado e em cada idioma. Por exemplo, o caminho da pasta para a edição do Visual Studio Enterprise em inglês é `%ProgramFiles%\Microsoft Visual Studio\2017\Enterprise\Common7\IDE\VC\VCTargets\1033`. Ajuste o caminho para seu idioma e a edição do Visual Studio. Cada regra no **páginas de propriedade** janela é representada por um arquivo XML nesta pasta. Certifique-se de que o arquivo seja exclusivamente nomeado na pasta.  
  
3.  Copiar o conteúdo de `%ProgramFiles%\Microsoft Visual Studio\2017\<VS Edition>\Common7\IDE\VC\VCTargets\<LCID>\cl.xml`, fechá-lo sem salvar as alterações e, em seguida, cole o conteúdo no seu novo arquivo XML. Você pode usar qualquer arquivo de esquema XML - essa é apenas uma pode ser usado para iniciar com um modelo.  
  
4.  No novo arquivo XML, modifique o conteúdo de acordo com suas necessidades. Certifique-se de alterar o **o nome da regra** e **Rule.DisplayName** na parte superior do arquivo.  
  
5.  Salve as alterações e feche o arquivo.  
  
6.  Arquivos XML em `%ProgramFiles%\Microsoft Visual Studio\2017\<VS Edition>\Common7\IDE\VC\VCTargets\<LCID>` são carregados quando o Visual Studio inicia. Portanto, para testar o novo arquivo, reinicie o Visual Studio.  
  
7.  Em **Solution Explorer**, clique em um projeto e, em seguida, clique em **propriedades**. No **páginas de propriedade** janela, no painel esquerdo, verifique se há um novo nó com o nome da sua regra.  
  
## <a name="see-also"></a>Consulte também  
 [MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)
