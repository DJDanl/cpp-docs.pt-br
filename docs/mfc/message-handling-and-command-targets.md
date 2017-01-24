---
title: "Manipula&#231;&#227;o de mensagem e destinos de comando | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "IOleCommandTarget"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "roteamento de comando, destinos de comando"
  - "destinos de comando"
  - "Interface IOleCommandTarget"
  - "lidando com erros, documentos ativos"
ms.assetid: e45ce14c-e6b6-4262-8f3b-4e891e0ec2a3
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipula&#231;&#227;o de mensagem e destinos de comando
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A interface `IOleCommandTarget` de expedição de comando define um mecanismo simples e extensível consulte e executar comandos.  Esse mecanismo é mais simples que `IDispatch` de automação como baseia\-se totalmente em um conjunto padrão de comandos; os comandos têm raramente argumentos, e nenhuma informação de tipo está envolvida \(a segurança de tipo é diminuída para argumentos de comando também\).  
  
 O design de interface de expedição de comando, cada comando de “pertence a um grupo” próprio comando que é identificado com **GUID**.  Em virtude disso, o pode definir um novo grupo e definir todos os comandos naquele grupo sem necessidade de coordenar a Microsoft ou qualquer outro provedor. \(É basicamente a mesma mídia de definição que **dispinterface** mais **dispIDs** na automação.  Há uma sobreposição aqui, embora esse mecanismo de roteamento do comando é apenas para o roteamento de comando e não para o script\/programação em grande escala como identificadores de automação.\)  
  
 `IOleCommandTarget` trata os seguintes cenários:  
  
-   Quando um objeto é ativado no local, somente as barras de ferramentas do objeto serão exibidas normalmente e barras de ferramentas do objeto podem ter os botões para alguns dos comandos do contêiner como **Imprimir**, **Imprimir Visualizar**, **Salvar**, `New`, **Zoom**, e outros. \(Os padrões de ativação no recomenda que os objetos remover esses botões de suas barras de ferramentas ou, as desabilitam pelo menos.  Esse design permite que os comandos sejam habilitados no entanto roteados para o manipulador à direita especificados.\) Atualmente, não há mecanismo para que o objeto despache esses comandos ao contêiner.  
  
-   Quando um documento ativo é inserido em um contêiner do documento ativo \(como a pasta do Office\), o contêiner pode precisar enviar comandos como **Imprimir**, **Página Instalação**, **Propriedades**, e outro para o documento ativo independente.  
  
 O roteamento do comando simples pode ser controlado com os padrões existentes e o `IDispatch`de automação.  No entanto, a sobrecarga envolvida com `IDispatch` é mais do que é necessário aqui, o que `IOleCommandTarget` fornece um conjunto mais simples obter as mesmas extremidades:  
  
 `interface IOleCommandTarget : IUnknown`  
  
 `{`  
  
 `HRESULT QueryStatus(`  
  
 `[in] GUID *pguidCmdGroup,`  
  
 `[in] ULONG cCmds,`  
  
 `[in,out][size_is(cCmds)] OLECMD *prgCmds,`  
  
 `[in,out] OLECMDTEXT *pCmdText);`  
  
 `HRESULT Exec(`  
  
 `[in] GUID *pguidCmdGroup,`  
  
 `[in] DWORD nCmdID,`  
  
 `[in] DWORD nCmdExecOpt,`  
  
 `[in] VARIANTARG *pvaIn,`  
  
 `[in,out] VARIANTARG *pvaOut);`  
  
 `}`  
  
 O método de `QueryStatus` aqui testa se um determinado conjunto de comandos, o conjunto que está sendo identificado com **GUID**, terá suporte.  Essa chamada preenche uma matriz de valores de **OLECMD** \(estruturas\) com a lista de comandos bem como retorna o texto que descreve o nome de um comando e\/ou de uma informações de status.  Quando o chamador deseja invocar um comando, pode passar o comando \(e\) **GUID**ajustado a **Exec** junto com as opções e argumentos, obtendo a parte de um valor de retorno.  
  
## Consulte também  
 [Contêineres de documento ativos](../mfc/active-document-containers.md)