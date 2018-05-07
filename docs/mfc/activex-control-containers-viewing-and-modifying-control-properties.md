---
title: 'Contêineres de controle ActiveX: Exibindo e modificando propriedades de controle | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- properties [MFC], viewing and modifying
- ActiveX control containers [MFC], viewing and modifying properties
- resource editors, viewing and modifying ActiveX controls
- ActiveX controls [MFC], properties
- controls [MFC], properties
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef443442cb19b9aaca82b74a0a5d8c72098d5cc2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="activex-control-containers-viewing-and-modifying-control-properties"></a>Contêineres de controle ActiveX: exibindo e modificando propriedades de controle
Quando você insere um controle ActiveX em um projeto, é útil exibir e alterar as propriedades com suporte pelo controle ActiveX. Este artigo descreve como usar o editor de recursos do Visual C++ para fazer isso.  
  
 Se seu aplicativo de contêiner de controle ActiveX usa controles inseridos, pode exibir e modificar as propriedades do controle no editor de recursos. Você também pode usar o editor de recurso para definir valores de propriedade em tempo de design. O editor de recursos, em seguida, salva automaticamente esses valores no arquivo de recurso do projeto. Qualquer instância do controle, em seguida, será necessário suas propriedades inicializadas com esses valores.  
  
 Este procedimento pressupõe que você inseriu um controle em seu projeto. Para obter informações, consulte [contêineres de controle ActiveX: inserindo um controle em um controle de aplicativo de contêiner](../mfc/inserting-a-control-into-a-control-container-application.md).  
  
 Exibindo as propriedades do controle a primeira etapa é adicionar uma instância do controle para o modelo de caixa de diálogo do projeto.  
  
### <a name="to-view-the-properties-of-a-control"></a>Para exibir as propriedades de um controle  
  
1.  No modo de exibição de recursos, abra o **diálogo** pasta.  
  
2.  Abra o modelo de caixa de diálogo principal.  
  
3.  Inserir um controle ActiveX usando o **Inserir controle ActiveX** caixa de diálogo. Para obter mais informações, consulte [exibindo e adicionando controles ActiveX a uma caixa de diálogo](../windows/viewing-and-adding-activex-controls-to-a-dialog-box.md).  
  
4.  Selecione o controle ActiveX na caixa de diálogo.  
  
5.  Na janela Propriedades, clique no **propriedades** botão.  
  
 Use o **propriedades** caixa de diálogo para modificar e testar novas propriedades imediatamente.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)

