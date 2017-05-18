---
title: "Assistente de página de propriedades ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.ppg.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding property pages
- ATL Property Page Wizard
ms.assetid: 6113e325-facd-4f68-b491-144d75209922
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 3e98f8edcb228a858bf0e2b2046db9152cd19a6b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atl-property-page-wizard"></a>Assistente de Página de Propriedades ATL
Este assistente [adiciona uma página de propriedades em um projeto ATL](../../atl/reference/adding-an-atl-property-page.md) ou a um projeto com suporte ATL. Uma página de propriedades ATL fornece uma interface de usuário para definir as propriedades (ou chamando os métodos) de um ou mais objetos COM.  
  
## <a name="remarks"></a>Comentários  
 Começando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro produzido por este assistente irá registrar seus componentes COM em **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Exceto para **nome curto**, todas as outras caixas podem ser editadas independentemente. Se você alterar o texto para **nome curto**, a alteração é refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** nome na seção de COM, a alteração é refletida no **tipo** e **ProgID** caixas. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve sua página de propriedades.  
  
> [!NOTE]
>  **Coclass** é editável apenas nonattributed projetos. Se seu projeto atribuído, você não pode editar **Coclass**.  
  
### <a name="c"></a>C++  
 Fornece informações para a classe C++ criada para implementar o objeto.  
  
|||  
|-|-|  
|Termo|Definição|  
|**Nome curto**|Define o nome abreviado do objeto. O nome que você fornecer determina a classe e **Coclass** nomeia o arquivo (**. cpp** e **. h**) nomes, o **tipo** nome e o **ProgID**, a menos que você altere os campos individualmente.|  
|**arquivo. h**|Define o nome do arquivo de cabeçalho para a nova classe de objeto. Por padrão, esse nome é baseado no nome que você fornecer **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.<br /><br /> O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.|  
|**Classe**|Define o nome da classe que implementa o objeto. Esse nome é baseado no nome que você fornecer **nome curto**, precedido por 'c'o prefixo típico para um nome de classe.|  
|**arquivo. cpp**|Define o nome do arquivo de implementação para a nova classe de objeto. Por padrão, esse nome é baseado no nome que você fornecer **nome curto**. Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.<br /><br /> O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.|  
|**Atribuído**|Indica se o objeto usa atributos. Se você estiver adicionando um objeto a um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar, ou seja, você pode adicionar apenas atribuída objetos a um projeto criado com o suporte do atributo.<br /><br /> Você pode adicionar um objeto atribuído somente a um projeto do ATL que usa atributos. Se você selecionar essa opção para um projeto do ATL que não tenha o atributo de suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.<br /><br /> Por padrão, os objetos que você adicionar depois de você definir essa opção são designados como atribuído (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.<br /><br /> Consulte [configurações do aplicativo, ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.|  
  
### <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indicar nesta página do Assistente para a página de propriedades usa atributos, você não pode alterar essa opção como ATL não inclui o `coclass` atributo.  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Opções, o Assistente de página de propriedades ATL](../../atl/reference/options-atl-property-page-wizard.md)   
 [Cadeias de caracteres, Assistente de página de propriedades ATL](../../atl/reference/strings-atl-property-page-wizard.md)   
 [Exemplo: Implementando uma página de propriedades](../../atl/example-implementing-a-property-page.md)


