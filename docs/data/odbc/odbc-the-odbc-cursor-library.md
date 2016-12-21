---
title: "ODBC: a biblioteca de cursores ODBC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "biblioteca de cursores [ODBC]"
  - "biblioteca de cursores [ODBC], instantâneos"
  - "cursores, Biblioteca de cursores ODBC"
  - "Drivers ODBC de Nível 1"
  - "biblioteca de cursores ODBC [ODBC]"
  - "Drivers ODBC, suporte a cursores"
  - "Drivers ODBC, Nível 1"
  - "ODBC, carimbo data/hora"
  - "atualizações posicionadas"
  - "posicionando cursores"
  - "instantâneos, suporte em ODBC"
  - "cursores estáticos"
  - "carimbos de data/hora, colunas de carimbo de data/hora ODBC"
ms.assetid: 6608db92-82b1-4164-bb08-78153c227be3
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ODBC: a biblioteca de cursores ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve a biblioteca de cursores ODBC e explica como usá\-la.  Para obter mais informações, consulte:  
  
-   [Drivers ODBC da biblioteca de cursores e nível 1](#_core_the_cursor_library_and_level_1_odbc_drivers)  
  
-   [Atualizações posicionadas e colunas de carimbo de data\/hora](#_core_positioned_updates_and_timestamp_columns)  
  
-   [Usando a biblioteca de cursores](#_core_using_the_cursor_library)  
  
 A biblioteca de cursores ODBC é uma biblioteca de vínculo dinâmico\) nativa \(DLL\) que esteja entre o gerenciador de driver ODBC e o driver.  Em termos de ODBC, um driver mantém um cursor para manter o controle de sua posição no conjunto de registros.  As marcas de cursor a posição no conjunto de registros que você já tem rolado — o registro atual.  
  
##  <a name="_core_the_cursor_library_and_level_1_odbc_drivers"></a> Drivers ODBC da biblioteca de cursores e nível 1  
 A biblioteca de cursores ODBC oferece aos drivers de nível 1 os seguintes recursos novos:  
  
-   Encaminhamento e rolagem para trás.  Os drivers de nível 2 não precisarem da biblioteca de cursores porque já estão roláveis.  
  
-   Suporte a instantâneos.  A biblioteca de cursores gerencia um buffer que contém os registros de instantâneo.  Esse buffer reflete as exclusões e as edições do programa para registros mas não das inclusões, as exclusões, ou as edições de outros usuários.  Em virtude disso, o instantâneo é tão atual quanto o buffer da biblioteca de cursores.  O buffer também não reflete suas próprias adições até que você chame **Requery**.  Dynasets não usa a biblioteca de cursores.  
  
 A biblioteca de cursores oferece instantâneos \(cursores estáticos\) se não normalmente têm suporte no driver.  Se o driver já oferece suporte a cursores estáticos, você não precisa carregar a biblioteca de cursores para obter suporte de instantâneo.  Se você usar a biblioteca de cursores, você pode usar apenas os instantâneos e conjuntos de registros de somente avanço.  Se o driver suporta dynasets \(cursores de KEYSET\_DRIVEN\) e você desejar usá\-los, você não deve usar a biblioteca de cursores.  Se você quiser usar instantâneos e dynasets, você deve baseá\-los em dois objetos diferentes de `CDatabase` \(duas conexões diferentes\) a menos que o driver dar suporte a ambos.  
  
##  <a name="_core_positioned_updates_and_timestamp_columns"></a> Atualizações posicionadas e colunas de carimbo de data\/hora  
  
> [!NOTE]
>  As fontes de dados ODBC são acessíveis por meio das classes MFC ODBC, como descrito neste tópico, ou as classes de \(DAO\) do objeto de acesso a dados de MFC.  
  
> [!NOTE]
>  Se o driver ODBC da suporte a **SQLSetPos**, que usa MFC o se disponível, este tópico não se aplica a ele.  
  
 A maioria dos drivers de nível 1 não dão suporte a atualizações posicionadas.  Esses drivers confiam na biblioteca de cursores para emular neste aspecto os recursos de drivers de nível 2.  A biblioteca de cursores emula o suporte de atualização posicionada fazendo uma atualização pesquisada nos campos constantes.  
  
 Em alguns casos, um conjunto de registros pode conter uma coluna de carimbo de data\/hora como um desses campos constantes.  Dois problemas ocorrem em usar conjuntos de registros de MFC com tabelas que contêm colunas de carimbo de data\/hora.  
  
 O primeiro problema está relacionados instantâneos atualizável em tabelas com colunas de carimbo de data\/hora.  Se a tabela para a qual o instantâneo é associado contém uma coluna de carimbo de data\/hora, você deve chamar **Requery** depois de chamar **Editar** e **Atualizar**.  Caso contrário, você não pode editar novamente o mesmo registro.  Quando você chama **Editar** e depois **Atualizar**, o registro será gravado na fonte de dados e a coluna de carimbo de data\/hora é atualizada.  Se você não chama **Requery**, o valor do carimbo de data\/hora do registro no instantâneo não corresponde ao carimbo de data\/hora correspondente na fonte de dados.  Quando você tentar atualizar novamente o registro, a fonte de dados pode desabilitar a atualização devido à incompatibilidade.  
  
 O segundo problema está relacionadas limitações da classe [CTime](../Topic/CTime%20Class.md) quando usado com a função de `RFX_Date` a informações de hora e data da transferência ou tabela.  Processando o objeto de `CTime` impor alguma sobrecarga no formato intermediário processamento adicional durante a transferência de dados.  O intervalo de datas de objetos de `CTime` talvez também seja muito limitado para alguns aplicativos.  Uma nova versão da função de `RFX_Date` assume um parâmetro ODBC **TIMESTAMP\_STRUCT** em vez de um objeto de `CTime` .  Para obter mais informações, consulte `RFX_Date` em [Macros e Globais](../Topic/Macros,%20Global%20Functions,%20and%20Global%20Variables.md)*na referência de MFC*.  
  
##  <a name="_core_using_the_cursor_library"></a> Usando a biblioteca de cursores  
 Quando você se conecta a uma fonte de dados — chamando [CDatabase::OpenEx](../Topic/CDatabase::OpenEx.md) ou [CDatabase::Open](../Topic/CDatabase::Open.md) — você pode especificar se deseja usar a biblioteca de cursores para a fonte de dados.  Se você estiver criando instantâneos nessa fonte de dados, para especificar a opção de **CDatabase::useCursorLib** no parâmetro de `dwOptions` a `OpenEx` ou para especificar **Verdadeiro** para o parâmetro de **bUseCursorLib** a **Abrir** \(o valor padrão é **Verdadeiro**\).  Se o driver ODBC da suporte a dynasets e você deseja abrir dynasets na fonte de dados, não use a biblioteca de cursores \(mascara algumas funcionalidades do driver necessária para dynasets\).  Nesse caso, não especifique **CDatabase::useCursorLib** em `OpenEx` ou não especificar **Falso** para o parâmetro de **bUseCursorLib** em **Abrir**.  
  
## Consulte também  
 [Noções básicas de ODBC](../../data/odbc/odbc-basics.md)