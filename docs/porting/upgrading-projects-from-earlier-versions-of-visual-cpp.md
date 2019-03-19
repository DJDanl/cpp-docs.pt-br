---
title: Atualizando projetos a partir de versões anteriores do Visual C++
ms.date: 11/04/2016
helpviewer_keywords:
- 32-bit code porting
- upgrading Visual C++ applications, 32-bit code
ms.assetid: 18cdacaa-4742-43db-9e4c-2d9e73d8cc84
ms.openlocfilehash: 8848dca10a75bec6f5ff6251a3af5be8e9a7b6e6
ms.sourcegitcommit: 9e85c2e029d06b4c1c69837437468718b4d54908
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/18/2019
ms.locfileid: "57816367"
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

## <a name="in-this-section"></a>Nesta seção

[Atualizar seu código para o CRT Universal](upgrade-your-code-to-the-universal-crt.md)<br/>
[Modificando WINVER e _WIN32_WINNT](modifying-winver-and-win32-winnt.md)<br/>
[Corrigir suas dependências em recursos internos de biblioteca](fix-your-dependencies-on-library-internals.md)<br/>
[Problemas de migração de ponto flutuante](floating-point-migration-issues.md)<br/>
[Usar direcionamento múltiplo nativo no Visual Studio para compilar projetos antigos](use-native-multi-targeting.md)<br/>
[Recursos do Visual C++ preteridos na versão prévia do Visual Studio 2019](features-deprecated-in-visual-studio.md)<br/>
[Alterações no sistema de build](build-system-changes.md)<br/>

## <a name="see-also"></a>Consulte também

[Novidades do Visual C++ no Visual Studio 2017](../what-s-new-for-visual-cpp-in-visual-studio.md)<br/>
[Histórico de alterações de 2003 a 2015 do Visual C++](../porting/visual-cpp-change-history-2003-2015.md)<br/>
[Comportamento não padrão](../cpp/nonstandard-behavior.md)
