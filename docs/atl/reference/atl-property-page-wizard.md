---
title: "Assistente de página de propriedades ATL | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: vc.codewiz.class.atl.ppg.overview
dev_langs: C++
helpviewer_keywords:
- ATL projects, adding property pages
- ATL Property Page Wizard
ms.assetid: 6113e325-facd-4f68-b491-144d75209922
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 9f97b4fcc84f9099ca7017eabd7ae5ead62cfe63
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-property-page-wizard"></a>Assistente de página de propriedades ATL
Este assistente [adiciona uma página de propriedades de um projeto de ATL](../../atl/reference/adding-an-atl-property-page.md) ou a um projeto com suporte ATL. Uma página de propriedades ATL fornece uma interface do usuário para definir as propriedades (ou chamar os métodos) de um ou mais objetos.  
  
## <a name="remarks"></a>Comentários  
 A partir do Visual Studio 2008, o script de registro produzido por este assistente irá registrar seus componentes COM em **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Exceto para **nome curto**, todas as outras caixas podem ser editadas independentemente. Se você alterar o texto para **nome curto**, a alteração será refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** nome na seção de COM, a alteração será refletida no **tipo** e **ProgID** caixas. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve sua página de propriedades.  
  
> [!NOTE]
>  **Coclass** é editável apenas nonattributed projetos. Se seu projeto atribuída, você não pode editar **Coclass**.  
  
### <a name="c"></a>C++  
 Fornece informações para a classe C++ criada para implementar o objeto.  
  
|||  
|-|-|  
|Termo|Definição|  
|**Nome curto**|Define o nome abreviado para o objeto. O nome que você fornecer determina a classe e **Coclass** nomeia o arquivo (**. cpp** e **. h**) nomes, o **tipo** nome e o  **ProgID**, a menos que você altere os campos individualmente.|  
|**arquivo. h**|Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará-lo para o local selecionado até que você clique **concluir** no assistente.<br /><br /> O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.|  
|**Class**|Define o nome da classe que implementa o objeto. Esse nome é baseado no nome que você fornecer em **nome curto**, precedidas por "C", o prefixo comum para um nome de classe.|  
|**arquivo. cpp**|Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.<br /><br /> O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.|  
|**Atribuído**|Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto de ATL atribuído, essa opção é selecionada e não está disponível para alterar, ou seja, você pode adicionar apenas atribuído objetos a um projeto criado com o suporte do atributo.<br /><br /> Você pode adicionar um objeto atribuído somente a um projeto ATL que usa atributos. Se você selecionar essa opção para um projeto de ATL que não tem o atributo suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.<br /><br /> Por padrão, os objetos que você adicionar depois que você definir esta opção são designados como atribuído (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.<br /><br /> Consulte [configurações do aplicativo, o Assistente de projeto de ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.|  
  
### <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar o projeto usando atributos, ou se você indicar nesta página do Assistente para a página de propriedades usa atributos, você não pode alterar essa opção como ATL não inclui o `coclass` atributo.  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Opções de Assistente de página de propriedades ATL](../../atl/reference/options-atl-property-page-wizard.md)   
 [Cadeias de caracteres, o Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)   
 [Exemplo: implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)

