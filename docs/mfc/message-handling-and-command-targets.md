---
title: "Destinos de comando e de manipulação de mensagens | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: IOleCommandTarget
dev_langs: C++
helpviewer_keywords:
- command targets [MFC]
- message handling [MFC], active documents
- IOleCommandTarget interface [MFC]
- command routing [MFC], command targets
ms.assetid: e45ce14c-e6b6-4262-8f3b-4e891e0ec2a3
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 81ec1f2a1f419715a3e8e9fbac2fcba3c7584a9b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="message-handling-and-command-targets"></a>Manipulação de mensagem e destinos de comando
A interface de Despache comando `IOleCommandTarget` define um mecanismo simple e extensível para consultar e executar comandos. Esse mecanismo é mais simples do que o da automação `IDispatch` porque ele se baseia totalmente em um conjunto padrão de comandos; comandos raramente têm argumentos, e nenhuma informação de tipo envolvida (segurança de tipo é reduzida para argumentos de comando também).  
  
 O design de interface de expedição de comando, cada comando pertence a um "grupo de comando" que é identificado com um **GUID**. Portanto, qualquer pessoa pode definir um novo grupo e definir todos os comandos dentro desse grupo sem nenhuma necessidade de coordenar com a Microsoft ou qualquer outro fornecedor. (Isso é essencialmente o mesmo meio de definição como um **dispinterface** mais **dispIDs** na automação. Há sobreposição aqui, embora esse mecanismo de roteamento de comando é apenas para roteamento de comando e não para o script/programação em grande escala como identificadores de automação.)  
  
 `IOleCommandTarget`lida com os seguintes cenários:  
  
-   Quando um objeto é ativado, somente as barras de ferramentas do objeto geralmente são exibidas e barras de ferramentas do objeto podem ter botões para alguns dos comandos contêiner como in-loco **impressão**, **Visualizar impressão**,  **Salvar**, `New`, **Zoom**e outros. (Ativação in-loco padrões recomendam que objetos remover esses botões das barras de ferramentas, ou em menos desabilitá-los. Esse design permite que esses comandos para ser habilitado e ainda é roteado para o manipulador de à direita.) No momento, não há nenhum mecanismo para o objeto de expedição estes comandos para o contêiner.  
  
-   Quando um documento ativo é inserido em um contêiner de documento ativo (como o Office Binder), o contêiner pode ser necessário enviar comandos de tais **impressão**, **Configurar página**, **propriedades**e outros para o documento ativo independente.  
  
 Este roteamento de comando simple pode ser manipulado por meio de padrões de automação existentes e `IDispatch`. No entanto, a sobrecarga envolvida com `IDispatch` é maior do que é necessário aqui, portanto `IOleCommandTarget` fornece um meio mais simples para atingir as extremidades mesmo:  
  
```  
interface IOleCommandTarget : IUnknown  
    {  
    HRESULT QueryStatus(  
        [in] GUID *pguidCmdGroup,  
        [in] ULONG cCmds,  
        [in,out][size_is(cCmds)] OLECMD *prgCmds,  
        [in,out] OLECMDTEXT *pCmdText);  
    HRESULT Exec(  
        [in] GUID *pguidCmdGroup,  
        [in] DWORD nCmdID,  
        [in] DWORD nCmdExecOpt,  
        [in] VARIANTARG *pvaIn,  
        [in,out] VARIANTARG *pvaOut);  
    }  
```  
  
 O `QueryStatus` método aqui testa se um determinado conjunto de comandos, o conjunto que está sendo identificado com um **GUID**, há suporte. Essa chamada preenche uma matriz de **OLECMD** valores (estruturas) com a lista com suporte de comandos, bem como retornar o texto que descreve o nome de um comando e/ou status de informações. Quando o chamador deseja invocar um comando, ele pode passar o comando (e o conjunto **GUID**) para **Exec** junto com as opções e argumentos, obter de volta um valor de retorno.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres de documento ativos](../mfc/active-document-containers.md)

