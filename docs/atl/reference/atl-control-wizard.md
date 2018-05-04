---
title: Assistente de controle ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.control.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding controls
- controls [ATL], adding to projects
- ATL Control Wizard
ms.assetid: 991f8e72-ffbc-4382-a4ce-e255acfba5b6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1df64cd0661a7f905ebcc068efb698306ac9007e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="atl-control-wizard"></a>Assistente de controle ATL
Inserções em um projeto de ATL (ou um projeto MFC com suporte ATL) um controle ATL. Você pode usar este assistente para inserir um dos três tipos de controles:  
  
-   Padrão de controle  
  
-   Controle composto  
  
-   Controle DHTML  
  
 Além disso, você pode especificar um controle mínimo, a remoção de interfaces do [Interfaces](../../atl/reference/interfaces-atl-control-wizard.md) lista, que são fornecidos como padrões para os controles para abrir na maioria dos contêineres. Você pode definir as interfaces que você deseja com suporte para o controle de **Interfaces** página do assistente.  
  
## <a name="remarks"></a>Comentários  
 O script de registro produzido por este assistente registrará seus componentes COM em HKEY_CURRENT_USER em vez de HKEY_LOCAL_MACHINE. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Exceto para **nome curto**, todas as outras caixas podem ser alteradas de forma independente. Se você alterar o texto para **nome curto**, a alteração será refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** nome na seção de COM, a alteração será refletida no **tipo** caixa, mas o **Interface** nome e **ProgID** fazer Não altere. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve seu controle.  
  
> [!NOTE]
>  **Coclass** é editável apenas nonattributed controles. Se seu projeto atribuída, você não pode editar **Coclass**.  
  
### <a name="c"></a>C++  
 Fornece informações para a classe C++ criada para implementar o objeto.  
  
 **Nome curto**  
 Define o nome abreviado para o objeto. O nome que você fornecer determina a classe e **Coclass** nomeia o arquivo (. CPP e. H) nomes de, o nome da interface e o **tipo** nomes, a menos que você altere os campos individualmente.  
  
 **Class**  
 Define o nome da classe que implementa o objeto. Esse nome é baseado no nome que você fornecer em **nome curto**, precedidas por "C", o prefixo comum para um nome de classe.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará-lo para o local selecionado até que você clique **concluir**.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **Atribuído**  
 Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto de ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.  
  
 Você pode adicionar um objeto atribuído somente a um projeto ATL que usa atributos. Se você selecionar essa opção para um projeto de ATL que não tem o atributo suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.  
  
 Por padrão, os objetos que você adicionar depois que você definir esta opção são designados como atribuído (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.  
  
 Consulte [configurações do aplicativo, o Assistente de projeto de ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.  
  
### <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar o projeto usando atributos, ou se você indicar nessa página do assistente que o controle usa atributos, você não pode alterar essa opção como ATL não inclui o **coclass** atributo.  
  
 **Interface**  
 Define o nome da interface para o objeto. Por padrão, um nome de interface é acrescentado com "I".  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto. Este campo não é preenchido automaticamente. Se você não preencher este campo manualmente, o controle pode não estar disponível para outras ferramentas. Por exemplo, os controles ActiveX que são gerados sem um `ProgID` não estão disponíveis no **Inserir controle ActiveX** caixa de diálogo. Para obter mais informações sobre a caixa de diálogo, consulte [Inserir caixa de diálogo de controle ActiveX](../../windows/insert-activex-control-dialog-box.md).  
  
## <a name="see-also"></a>Consulte também  
 [Controle ATL](../../atl/reference/adding-an-atl-control.md)   
 [Adicionando funcionalidade para o controle composto](../../atl/adding-functionality-to-the-composite-control.md)   
 [Princípios básicos de objetos COM da ATL](../../atl/fundamentals-of-atl-com-objects.md)

