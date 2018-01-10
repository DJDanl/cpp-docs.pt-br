---
title: Mescla do Menu Ajuda | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- menus [MFC], merging
- merging Help menus [MFC]
- Help [MFC], for active document containers
ms.assetid: 9d615999-79ba-471a-9288-718f0c903d49
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c4d3ae9509edcbe79417bb37d02f4f585b2da653
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="help-menu-merging"></a>Mescla do menu Ajuda
Quando um objeto está ativo em um contêiner, o menu de mesclagem de protocolo de documentos OLE fornece o controle total do objeto do **ajuda** menu. Como resultado, os tópicos de Ajuda do contêiner não estão disponíveis, a menos que o usuário desativa o objeto. A arquitetura de confinamento do documento ativo expande as regras de menu no local de mesclagem para permitir que o contêiner e um documento ativo está ativo para compartilhar o menu. As novas regras são convenções simplesmente adicionais sobre qual componente possui que faz parte do menu e como menu compartilhado é construído.  
  
 A nova convenção é simple. Em documentos ativos, o **ajuda** menu tem dois itens de menu de nível superior organizadas da seguinte forma:  
  
 `Help`  
  
 `Container Help >`  
  
 `Object Help    >`  
  
 Por exemplo, quando uma seção do Word está ativa no Office Binder, em seguida, o **ajuda** menu terá a seguinte aparência:  
  
 `Help`  
  
 `Binder Help >`  
  
 `Word Help   >`  
  
 Ambos os itens de menu são menus em cascata sob a qual os itens de menu adicionais específicos para o contêiner e o objeto são fornecidos para o usuário. Quais itens aparecem aqui irão variar com o contêiner e os objetos envolvidos.  
  
 Para construir essa mescladas **ajuda** menu, a arquitetura de confinamento do documento ativo modifica o procedimento de documentos OLE normal. De acordo com a documentos OLE, a barra de menu mesclado pode ter seis grupos de menus, ou seja, **arquivo**, **editar**, **contêiner**, `Object`, **janela**, **Ajuda**, nessa ordem. Em cada grupo, pode ser zero ou mais menus. Os grupos de **arquivo**, **contêiner**, e **janela** pertencer ao contêiner e os grupos de **editar**, **, edeobjeto** e **ajuda** pertence ao objeto. Quando o objeto quer fazer a mesclagem de menu, ele cria uma barra de menus em branco e passa para o contêiner. O contêiner, em seguida, insere seus menus, chamando **IOleInPlaceFrame::InsertMenus**. O objeto também passa uma estrutura que é uma matriz de seis valores longos (**OLEMENUGROUPWIDTHS**). Depois de inserir os menus, o contêiner de marca como muitos menus ele adicionado em cada um de seus grupos e, em seguida, retorna. O objeto insere seus menus, prestando atenção à contagem de menus em cada grupo de contêiner. Por fim, o objeto passa a barra de menus mescladas e a matriz (que contém a contagem de menus em cada grupo) para OLE, que retorna um opaco "descritor de menu" tratar. Mais tarde o objeto passa esse identificador e a barra de menu mesclado para o contêiner, por meio de **IOleInPlaceFrame::SetMenu**. Neste momento, o contêiner exibe a barra de menu mesclado e também passa o identificador para OLE, para que o OLE pode fazer adequada de expedição de mensagens do menu.  
  
 No procedimento a modificação de documento ativo, o objeto deve ser inicializado pela primeira vez o **OLEMENUGROUPWIDTHS** elementos como zero antes de passar para o contêiner. O contêiner executará uma inserção de menu normal com uma exceção: as inserções de contêiner um **ajuda** menu como o último item e armazena um valor de 1 na última entrada (o sexto) do **OLEMENUGROUPWIDTHS** matriz (ou seja, largura [5], que pertence ao grupo de Ajuda do objeto). Isso **ajuda** menu terá apenas um item que é um submenu, o "**contêiner ajuda** >" menu cascade conforme descrito anteriormente.  
  
 O objeto, em seguida, executa o código de inserção de menu normal, exceto que antes de inserir sua **ajuda** menu, ele verifica a entrada sexto do **OLEMENUGROUPWIDTHS** matriz. Se o valor é 1 e o nome do último menu é **ajuda** (ou cadeia de caracteres localizada apropriado), em seguida, insere o objeto seu **ajuda** menu como submenu do contêiner **ajuda** menu.  
  
 O objeto, em seguida, define o elemento sexto de **OLEMENUGROUPWIDTHS** como zero e incrementa o elemento quinto por um. Isso permite que o OLE saber que o **ajuda** menu pertence ao contêiner e as mensagens de menu correspondente a esse menu (e seus submenus) devem ser roteadas para o contêiner. Em seguida, é responsabilidade do contêiner para encaminhar `WM_INITMENUPOPUP`, **WM_SELECT**, **WM_COMMAND**e outras mensagens relacionadas de menu que pertencem à parte do objeto de **ajuda**  menu. Isso é feito usando `WM_INITMENU` para limpar um sinalizador que informa o contêiner se o usuário navegar para o objeto **ajuda** menu. Em seguida, observa o contêiner `WM_MENUSELECT` para entrada em ou sair de qualquer item no **ajuda** menu que o contêiner não se adicionou. Na entrada, isso significa que o usuário navegar em um menu de objeto para o contêiner define o sinalizador "no menu de Ajuda do objeto" e usa o estado do sinalizador para encaminhar qualquer `WM_MENUSELECT`, `WM_INITMENUPOPUP`, e **WM_COMMAND** mensagens, como mínimo, a a janela de objeto. (Na saída, o contêiner limpa o sinalizador e, em seguida, processa essas mensagens mesmo em si.) O contêiner deve usar a janela retornada do objeto de **IOleInPlaceActiveObejct::GetWindow** funcionar como o destino para essas mensagens.  
  
 Se o objeto detecta um zero no elemento do sexto **OLEMENUGROUPWIDTHS**, ele procede de acordo com as regras normais de documentos OLE. Esse procedimento abrange contêineres que participam **ajuda** , bem como os que não a mesclagem de menu.  
  
 Quando o objeto chama **IOleInPlaceFrame::SetMenu**, antes de exibir o menu mesclado barras, as verificações de contêiner se o **ajuda** menu tem um submenu adicional, além do contêiner tem inserido. Se, o contêiner deixa seu **ajuda** menu da barra de menu mesclado. Se o **ajuda** menu não tem um submenu adicional, o contêiner removerá seu **ajuda** menu da barra de menu mesclado. Esse procedimento abrange objetos que participam de **ajuda** , bem como os que não a mesclagem de menu.  
  
 Finalmente, quando for hora de desmontar o menu, o objeto remove os dados inseridos **ajuda** menu além de remover o outro inserido menus. Quando o contêiner remove seus menus, ele removerá seu **ajuda** menu além dos outros menus que foi inserido.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de documento ativos](../mfc/active-document-containers.md)

