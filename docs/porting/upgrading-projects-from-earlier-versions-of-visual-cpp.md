---
title: Atualizando projetos de versões anteriores do Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- 32-bit code porting
- upgrading Visual C++ applications, 32-bit code
ms.assetid: 18cdacaa-4742-43db-9e4c-2d9e73d8cc84
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ed8a8ab088f3fbb10b5f477d125dbf3f2a7ac932
ms.sourcegitcommit: e9ce38decc9f986edab5543de3464b11ebccb123
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/13/2018
ms.locfileid: "42578269"
---
# <a name="upgrading-projects-from-earlier-versions-of-visual-c"></a>Atualizando projetos a partir de versões anteriores do Visual C++
Na maioria dos casos, você pode abrir um projeto que foi criado em uma versão anterior do Visual Studio. No entanto, para fazer isso, o Visual Studio atualiza o projeto. Se você salvar esse projeto atualizado, ele não poderá ser aberto na versão anterior.  
  
> [!IMPORTANT]
> Se você tentar converter um projeto que já foi convertido, o Visual Studio solicitará confirmação porque a reconversão exclui arquivos existentes.  
  
Muitos projetos e soluções atualizados podem ser compilados com êxito sem modificação. No entanto, alguns projetos podem exigir alterações nas configurações, no código-fonte, ou ambos. Recomendamos que você use as seguintes diretrizes para solucionar os problemas das configurações primeiro e depois, se o projeto ainda não for compilado, você poderá solucionar os problemas de código. Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](../porting/overview-of-potential-upgrade-issues-visual-cpp.md).  
  
1. Faça uma cópia dos arquivos existentes do projeto e da solução. Instale a versão atual do Visual Studio e a versão anterior paralelamente para que você possa comparar as versões dos arquivos se quiser.  
  
2. Na versão atual do Visual Studio, abra – e, portanto, atualize – a cópia do projeto ou da solução e salve-a.  
  
3. Para cada projeto convertido, abra o menu de atalho e escolha **Propriedades**. Em **Propriedades de Configuração**, selecione **Geral** e, para **Conjunto de Ferramentas da Plataforma**, selecione a versão atual. (Por exemplo, para o Visual Studio 2017, selecione **v141**.)  
  
4. Compile a solução. Se a compilação falhar, modifique as configurações e recompile.  
  
As fontes de dados estão contidas em um projeto de banco de dados separado para que você possa modificar e depurar mais facilmente os procedimentos armazenados nessas fontes. Se você atualizar o projeto C++ que contém fontes de dados, um projeto de banco de dados separado será criado automaticamente.  
  
Para obter informações sobre como atualizar as versões de destino do Windows, consulte [Modificando WINVER e _WIN32_WINNT](../porting/modifying-winver-and-win32-winnt.md).  
  
## <a name="see-also"></a>Consulte também  

[Alterações no sistema de build](../build/build-system-changes.md)  
[O que há de novo no Visual C++ no Visual Studio 2017](../what-s-new-for-visual-cpp-in-visual-studio.md) 
[Histórico de alterações de 2003 – 2015 do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)   
[Comportamento não padrão](../cpp/nonstandard-behavior.md)