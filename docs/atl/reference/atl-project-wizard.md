---
title: ATL Project Wizard
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.atl.com.overview
helpviewer_keywords:
- ATL projects, creating
- ATL Project Wizard
ms.assetid: 564d2aaf-5b8e-4c2a-a925-ca40a283ea34
ms.openlocfilehash: 384847738f5410d750d53d3125c18f6a5256cccf
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65221249"
---
# <a name="atl-project-wizard"></a>ATL Project Wizard

A biblioteca ATL (Active Template) é um conjunto de classes C++ baseadas em modelo que simplificam a criação de objetos pequenos e rápidos. A ATL Project Wizard cria um projeto com as estruturas para conter objetos COM.

## <a name="overview"></a>Visão geral

Esta página do assistente descreve atual [configurações de aplicativo para o projeto da ATL](../../atl/reference/application-settings-atl-project-wizard.md) você está criando. Por padrão, o projeto tem as seguintes configurações:

- Biblioteca de vínculo dinâmico especifica que o servidor é uma DLL e, portanto, um servidor em processo.

- Especifica que o projeto usa atributos de atribuído.

Para alterar esses padrões, clique em **configurações do aplicativo** na coluna à esquerda das alterações assistente e verifique na página do Assistente de projeto de ATL.

Para obter informações sobre as configurações de projeto padrão, incluindo a escolha do conjunto de caracteres e a vinculação de padrões, consulte [configurações de projeto de ATL padrão](../../atl/reference/default-atl-project-configurations.md).

Depois de criar um projeto da ATL, você pode adicionar objetos ou controles ao seu projeto usando o Visual C++ [assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md). Você pode fazer os seguintes tipos de aprimoramentos para um projeto ATL básico usando os assistentes de código:

- [Adicionar o objeto e controles para um projeto ATL](../../atl/reference/adding-objects-and-controls-to-an-atl-project.md)

- [Adicione uma nova interface em um projeto ATL](../../atl/reference/adding-a-new-interface-in-an-atl-project.md)

- [Adicionar um componente COM+ 1.0 para um projeto ATL](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)

Além disso, considere estas tarefas quando você cria e aprimorar um projeto ATL:

- [Tornar um noncreatable de objeto do ATL](../../atl/reference/making-an-atl-object-noncreatable.md)

- [Otimizar o compilador para um projeto ATL](../../atl/reference/specifying-compiler-optimization-for-an-atl-project.md)

Você pode especificar as propriedades do projeto (por exemplo, [se deseja vincular estaticamente ao CRT](../../atl/programming-with-atl-and-c-run-time-code.md)) na [propriedades do projeto](../../build/reference/general-property-page-project.md) página e você pode definir [configurações de build](/visualstudio/ide/understanding-build-configurations) para um Projeto ATL.

## <a name="see-also"></a>Consulte também

[Projetos do Visual Studio – C++](../../build/creating-and-managing-visual-cpp-projects.md)<br/>
[C++tipos de projeto no Visual Studio](../../build/reference/visual-cpp-project-types.md)<br/>
[Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)<br/>
[Programando com código de tempo de execução C e da ATL](../../atl/programming-with-atl-and-c-run-time-code.md)<br/>
[Tutorial](../../atl/active-template-library-atl-tutorial.md)
