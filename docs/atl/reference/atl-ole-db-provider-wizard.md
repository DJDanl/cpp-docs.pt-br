---
title: "Assistente do provedor do OLE DB de ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.provider.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente do provedor do OLE DB de ATL"
  - "Projetos de ATL, adicionando provedores do OLE DB de ATL"
ms.assetid: cf91ba78-01d1-4d12-b673-e95d96bfbebe
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente do provedor do OLE DB de ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O assistente cria classes que compõem um provedor OLE DB.  
  
## Comentários  
 Iniciando com [!INCLUDE[vs_orcas_long](../../atl/reference/includes/vs_orcas_long_md.md)], o script de registro gerado pelo assistente irá registrar seus componentes COM em **HKEY\_CURRENT\_USER** em vez de **HKEY\_LOCAL\_MACHINE**.  Para alterar esse comportamento, defina a opção de **Componente do registro para todos os usuários** do assistente de ATL.  
  
 A tabela a seguir descreve as opções para o assistente do provedor do OLE DB de ATL:  
  
 **Nome curto**  
 Digite o nome curto do provedor a ser criado.  Outras caixas de edição no assistente popularão automaticamente com base em que você digite aqui.  Você pode editar as outras caixas de nome se você deseja.  
  
 **Coclass**  
 O nome de coclass.  O nome de ProgID será alterado para coincidir com este nome.  
  
 **atribuído**  
 Esta opção especifica se o assistente criará classes do provedor usando atributos ou declarações de modelo.  Quando você seleciona essa opção, o assistente usa atributos em vez das declarações do modelo \(esta é a opção padrão se você criou um projeto designado\).  Quando você desmarcar essa opção, o assistente usa declarações de modelo em vez de atributos \(esta é a opção padrão se você criou um projeto não atribuído\).  
  
 Se você selecionar esta opção quando você criar um projeto não tiver atribuído, o assistente adverte\-o que o projeto será convertido em um projeto atribuído e irá perguntar se deseja continuar ou não.  
  
 **ProgID**  
 ProgID, ou identificador de programação, é uma cadeia de caracteres de texto que seu aplicativo pode usar em vez de GUID.  O nome de ProgID a forma *Projectname*.*Coclassname*.  
  
 **Versão**  
 O número de versão do provedor.  O padrão é 1.  
  
 **Classe de fonte de dados**  
 O nome da classe da fonte de dados, C fonte de`Shortname`do formulário.  
  
 **Arquivo fonte de dados .h**  
 O arquivo de cabeçalho para a classe da fonte de dados.  Você pode editar o nome do arquivo ou selecione um arquivo de cabeçalho existente.  
  
 **Classe de sessão**  
 O nome da classe de sessão, da sessão de C`Shortname`do formulário.  
  
 **Arquivo .h de sessão**  
 O arquivo de cabeçalho para a classe de sessão.  Você pode editar o nome do arquivo ou selecione um arquivo de cabeçalho existente.  
  
 **Classe de comando**  
 O nome da classe de comando, de comando c`Shortname`do formulário.  
  
 **Arquivo .h de comando**  
 O arquivo de cabeçalho para a classe de comando.  Este nome não pode ser editado e não depende de nome de arquivo de cabeçalho de rowset.  
  
 **classe de Rowset**  
 O nome da classe de rowset, do formulário C`Shortname`Rowset.  
  
 **arquivo de Rowset .h**  
 O arquivo de cabeçalho para a classe de rowset.  Você pode editar o nome do arquivo ou selecione um arquivo de cabeçalho existente.  
  
 **arquivo de Rowset .cpp**  
 O arquivo da implementação do provedor.  Você pode editar o nome do arquivo ou selecione um arquivo de implementação.  
  
## Consulte também  
 [Provedor do OLE DB de ATL](../../atl/reference/adding-an-atl-ole-db-provider.md)