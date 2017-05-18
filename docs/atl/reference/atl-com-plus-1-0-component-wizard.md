---
title: ATL COM+ 1.0 Component Wizard | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.mts.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding components
- ATL COM+ 1.0 Component Wizard
ms.assetid: 11670681-8671-4122-96a4-2e52f8dadce0
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
ms.openlocfilehash: 2729975c5e823965f4f5c16d5bfe317ce10a3670
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atl-com-10-component-wizard"></a>Assistente de Componente de ATL COM+ 1.0
Use este assistente para adicionar um objeto ao seu projeto que ofereça suporte a serviços COM+ 1.0, incluindo transações.  
  
 Você pode especificar se o objeto oferece suporte a interfaces duplas e automação. Você também pode indicar o suporte para a interface de informações de erro, controle de objeto avançado, transações e enfileiramento de mensagens assíncronas.  
  
## <a name="remarks"></a>Comentários  
 Começando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro produzido por este assistente irá registrar seus componentes COM em **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Com exceção de **nome curto**, todas as outras caixas podem ser editadas, independentemente dos outros. Se você alterar o texto para **nome curto**, a alteração é refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** nome na seção de COM, a alteração é refletida no **tipo** e **ProgID** caixas, mas o **Interface** nome não é alterado. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve seu controle.  
  
 **Nome curto**  
 Define o nome abreviado do objeto. O nome que você fornecer determina o `Class` e `Coclass` nomes, o **arquivo. cpp** e **. h arquivo** nomes, o **Interface** nome, o **tipo** nomes e o **ProgID**, a menos que você altere os campos individualmente.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto. Por padrão, esse nome é baseado no nome que você fornecer **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você escolher um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **Classe**  
 Define o nome da classe a ser criado. Esse nome é baseado no nome fornecidas nos **nome curto**, precedido por 'c'o prefixo típico para um nome de classe.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto. Por padrão, esse nome se baseia o nome fornecido no **nome curto**. Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **Atribuído**  
 Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.  
  
 Se você selecionar essa opção para um projeto do ATL que não tenha o atributo de suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.  
  
 Os objetos que você adicionar a configuração dessa opção a seguir são designados como atribuído por padrão (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.  
  
 Consulte [configurações do aplicativo, ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.  
  
### <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar seu projeto usando atributos, ou se você indicar nessa página do assistente que o componente COM+ 1.0 usa atributos, você não pode alterar essa opção como ATL não inclui o `coclass` atributo.  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro  
  
 **Interface**  
 Define a interface que você criar para o objeto. Essa interface contém seus métodos personalizados.  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [ATL componente COM+ 1.0](../../atl/reference/adding-an-atl-com-plus-1-0-component.md)


