---
title: "Assistente de componente de página do Active Server ATL | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.asp.overview
dev_langs:
- C++
helpviewer_keywords:
- ASP components, creating in ATL
- ATL Active Server Page Component Wizard
ms.assetid: 5a5cb904-dbbf-44ea-ad3d-2ddd14c1d3c5
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
ms.openlocfilehash: db782a2f9f37b44be5a6c40780a1a93243b6257e
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="atl-active-server-page-component-wizard"></a>Assistente do Componente Active Server Pages da ATL
Este assistente insere no projeto de um componente Active Server Pages (ASP). O Microsoft Internet Information Services (IIS) usa componentes ASP como parte de sua arquitetura de desenvolvimento aprimorada página da Web.  
  
 Usando esse assistente, você pode especificar que o componente de encadeamento do modelo e o suporte de agregação. Você também pode indicar o suporte para a interface de informações de erro, pontos de conexão e empacotamento de segmentação livre.  
  
## <a name="remarks"></a>Comentários  
 Começando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro produzido por este assistente irá registrar seus componentes COM em **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Exceto para **nome curto**, todas as outras caixas podem ser editadas, independentemente dos outros. Se você alterar o texto para **nome curto**, a alteração é refletida nos nomes de todas as outras caixas nesta página.  
  
 Se você alterar o **Coclass** nome na seção de COM, a alteração é refletida no **tipo** e **ProgID** caixas, mas o **Interface** nome não é alterado. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve seu controle.  
  
### <a name="c"></a>C++  
 Fornece informações para a classe C++ criada para o objeto.  
  
 **Nome curto**  
 Define o nome de raiz para o objeto. O nome que você fornecer determina o `Class` e **Coclass** nomes, o **arquivo. cpp** e **. h arquivo** nomes, o **Interface** nome, o **tipo** nomes e o **ProgID**, a menos que você altere os campos individualmente.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a nova classe de objeto. Por padrão, esse nome é baseado no nome que você fornecer **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **Classe**  
 Define o nome da classe a ser criado. Esse nome é baseado no nome que você fornecer **nome curto**, precedido por 'c'o prefixo típico para um nome de classe.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a nova classe de objeto. Por padrão, esse nome é baseado no nome que você fornecer **nome curto**. Clique no botão de reticências para salvar o nome de arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especifique outro nome de arquivo.  
  
 **Atribuído**  
 Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.  
  
 Se você selecionar essa opção para um projeto do ATL que não tenha o atributo de suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.  
  
 Por padrão para projetos nonattributed, quaisquer objetos que você adicionar depois de você definir essa opção são designados como atribuído (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.  
  
 Consulte [configurações do aplicativo, ATL Project Wizard](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.  
  
### <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **Coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto. Se seu projeto ou este objeto usa atributos, você não pode alterar essa opção como ATL não inclui o **coclass** atributo.  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro para o coclass.  
  
 **Interface**  
 Define a interface que você criar para o objeto. Essa interface contém seus métodos personalizados.  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Componente de página de servidor ativo do ATL](../../atl/reference/adding-an-atl-active-server-page-component.md)


