---
title: Assistente de objeto simples de ATL | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.simple.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding objects
- ATL Simple Object Wizard
ms.assetid: f7f85741-9aad-4543-a917-a29b996364da
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0ff9648cfc350f724a333e38622d082d8d399b3b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32363963"
---
# <a name="atl-simple-object-wizard"></a>Assistente de objeto simples de ATL
Este assistente insere o projeto de um objeto COM mínima. Use esta página do Assistente para especificar os nomes que identificam a classe C++ e arquivos para o objeto e sua funcionalidade de COM.  
  
 Use o [opções](../../atl/reference/options-atl-simple-object-wizard.md) página deste assistente para especificar o modelo de threading do objeto, agregação de seu suporte, e se ele dá suporte a interfaces duplas e automação. Você também pode indicar o suporte para a interface de informações de erro, pontos de conexão, o suporte do Internet Explorer e free-thread marshaling.  
  
## <a name="remarks"></a>Comentários  
 A partir do Visual Studio 2008, o script de registro produzido por este assistente irá registrar seus componentes COM em **HKEY_CURRENT_USER** em vez de **HKEY_LOCAL_MACHINE**. Para modificar esse comportamento, defina o **registrar o componente para todos os usuários** opção do assistente ATL.  
  
## <a name="names"></a>Nomes  
 Especifique os nomes para o objeto, interface e classes a serem adicionadas ao seu projeto. Exceto para **nome curto**, todas as outras caixas podem ser editadas independentemente de outras pessoas. Se você alterar o texto para **nome curto**, a alteração será refletida nos nomes de todas as outras caixas nesta página. Se você alterar o **Coclass** nome na seção de COM, a alteração será refletida no **tipo** e **ProgID** caixas, mas o **Interface** nome não é alterado. Esse comportamento de nomenclatura é projetado para tornar todos os nomes facilmente identificável para você à medida que desenvolve seu controle.  
  
> [!NOTE]
>  **Coclass** é editável apenas nonattributed projetos. Se seu projeto atribuída, você não pode editar **Coclass**.  
  
## <a name="c"></a>C++  
 Fornece informações para a classe C++ criada para o objeto.  
  
 **Nome curto**  
 Define o nome abreviado para o objeto. O nome que você fornecer determina o `Class` e **Coclass** nomes, o **arquivo. cpp** e **. h arquivo** nomes, o **Interface**nome, o **tipo** nomes e o **ProgID**, a menos que você altere os campos individualmente.  
  
 **arquivo. h**  
 Define o nome do arquivo de cabeçalho para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha, ou para acrescentar a declaração de classe para um arquivo existente. Se você selecionar um arquivo existente, o assistente não salvará-lo para o local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicitará que você indique se a declaração de classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **Class**  
 Define o nome da classe a ser criado. Esse nome é baseado no nome que você fornecer em **nome curto**, precedidas por "C", o prefixo comum para um nome de classe.  
  
 **arquivo. cpp**  
 Define o nome do arquivo de implementação para a classe do novo objeto. Por padrão, esse nome é baseado no nome que você fornecer em **nome curto**. Clique no botão de reticências para salvar o nome do arquivo para o local de sua escolha. O arquivo não é salvo no local selecionado até que você clique **concluir** no assistente.  
  
 O assistente não substituirá um arquivo. Se você selecionar o nome de um arquivo existente, quando você clica em **concluir**, o assistente solicita que você indique se a implementação da classe deve ser anexada ao conteúdo do arquivo. Clique em **Sim** para anexar o arquivo; clique em **não** para retornar ao assistente e especificar outro nome de arquivo.  
  
 **Atribuído**  
 Indica se o objeto usa atributos. Se você estiver adicionando um objeto para um projeto de ATL atribuído, essa opção é selecionada e não está disponível para alterar. Ou seja, você pode adicionar apenas os objetos atribuídos a um projeto criado com o suporte do atributo.  
  
 Você pode adicionar um objeto atribuído somente a um projeto ATL que usa atributos. Se você selecionar essa opção para um projeto de ATL que não tem o atributo suporte, o assistente solicita que você especifique se deseja adicionar suporte de atributo para o projeto.  
  
 Por padrão, os objetos que você adicionar depois que você definir esta opção são designados como atribuído (a caixa de seleção está selecionada). Você pode desmarcar essa caixa para adicionar um objeto que não usa atributos.  
  
 Consulte [configurações do aplicativo, o Assistente de projeto de ATL](../../atl/reference/application-settings-atl-project-wizard.md) e [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.  
  
## <a name="com"></a>COM  
 Fornece informações sobre a funcionalidade de COM para o objeto.  
  
 **coclass**  
 Define o nome da classe de componente que contém uma lista de interfaces suportadas pelo objeto.  
  
> [!NOTE]
>  Se você criar o projeto usando atributos, ou se você indicar nessa página do assistente que o objeto usa atributos, você não pode alterar essa opção como ATL não inclui o `coclass` atributo.  
  
 **Tipo**  
 Define a descrição do objeto que será exibido no registro  
  
 **Interface**  
 Define a interface que você criar para o objeto. Essa interface contém seus métodos personalizados.  
  
 **ProgID**  
 Define o nome que podem usar contêineres em vez do CLSID do objeto.  
  
## <a name="see-also"></a>Consulte também  
 [Objeto ATL simples](../../atl/reference/adding-an-atl-simple-object.md)

