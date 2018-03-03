---
title: RW2002 de erro do compilador de recurso | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- RW2002
dev_langs:
- C++
helpviewer_keywords:
- RW2002
ms.assetid: b1d1a49b-b50b-4b0b-9f09-c7762e2dbe8f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: db322791c3804f387c452b3839260826585a2e30
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="resource-compiler-error-rw2002"></a>Erro RW2002 (compilador de recurso)
Erro de análise  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  **Tipo de acelerador necessários (ASCII ou VIRTKEY)**  
  
     O `type` campo o **ACELERADORES** instrução deve conter o valor de ASCII ou VIRTKEY.  
  
2.  **INÍCIO esperado na tabela de aceleradores**  
  
     O **começar** palavra-chave deve seguir imediatamente a **ACELERADORES** palavra-chave.  
  
3.  **INÍCIO esperado na caixa de diálogo**  
  
     O **começar** palavra-chave deve seguir imediatamente a **diálogo** palavra-chave.  
  
4.  **Esperado no menu de início**  
  
     O **começar** palavra-chave deve seguir imediatamente a **MENU** palavra-chave.  
  
5.  **INÍCIO esperado em RCData**  
  
     O **começar** palavra-chave deve seguir imediatamente a **RCDATA** palavra-chave.  
  
6.  **COMEÇAR a palavra-chave esperada na tabela de cadeia de caracteres**  
  
     O **começar** palavra-chave deve seguir imediatamente a **STRINGTABLE** palavra-chave.  
  
7.  **Não é possível reutilizar a constantes de cadeia de caracteres**  
  
     Você está usando o mesmo valor duas vezes em um **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais. Cada ID em um **STRINGTABLE** devem ser exclusivos. Para máxima eficiência, use constantes contíguos com início em um múltiplo de 16.  
  
8.  **Caractere fora do intervalo de controle [^ A - ^ Z]**  
  
     Um caractere de controle no **ACELERADORES** instrução é inválida. O caractere após o cursor (**^**) deve estar entre A e Z, inclusive.  
  
9. **Menus vazios não permitidos**  
  
     Um **final** palavra-chave aparece antes dos itens de menu são definidos no **MENU** instrução. O compilador de recurso não permite que os menus vazios. Verifique se você não tem qualquer Abrir aspas dentro de **MENU** instrução.  
  
10. **TÉRMINO esperado na caixa de diálogo**  
  
     O **final** palavra-chave deve ocorrer no final de um **diálogo** instrução. Verifique se não há nenhuma aspas de abertura à esquerda da instrução anterior.  
  
11. **TÉRMINO esperado no menu**  
  
     O **final** palavra-chave deve vir no final de um **MENU** instrução. Verifique se você não tem quaisquer aspas abertas ou um par incompatível de **começar** e **final** instruções.  
  
12. **Vírgula esperada na tabela de teclas aceleradoras**  
  
     O compilador de recurso requer uma vírgula entre o `event` e *idvalue* campos de **ACELERADORES** instrução.  
  
13. **Nome da classe de controle esperado**  
  
     O `class` campo de um **controle** instrução no **diálogo** instrução deve ser um dos seguintes tipos: botão, caixa de COMBINAÇÃO, editar, caixa de listagem, barra de ROLAGEM, estático, ou definido pelo usuário. Verifique se que a classe está escrita corretamente.  
  
14. **Esperado um nome de face de fonte**  
  
     O *face de tipos* campo da opção na fonte de **caixa de diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas. Este campo especifica o nome de uma fonte.  
  
15. **Valor de ID esperado para menuitem**  
  
     O **MENU** instrução deve conter um *menuID* campo, que especifica o nome ou o número que identifica o recurso de menu.  
  
16. **Cadeia de caracteres esperada de menu**  
  
     Cada **MENUITEM** e **pop-up** instrução deve conter um *texto* campo, que é uma cadeia de caracteres entre aspas duplas que especifica o nome do item de menu ou menu pop-up menu. Um **MENUITEM SEPARADOR** instrução não requer nenhuma cadeia de caracteres entre aspas.  
  
17. **Esperado um valor numérico de comando**  
  
     O compilador de recurso estava esperando um numérico *idvalue* campo o **ACELERADORES** instrução. Certifique-se de que você usou um `#define` constante para especificar o valor e que a constante está escrita corretamente.  
  
18. **Esperado constante numérica na tabela de cadeia de caracteres**  
  
     Uma constante numérica, definido em uma `#define` instrução, deve seguir imediatamente a **começar** palavra-chave em um **STRINGTABLE** instrução.  
  
19. **Esperado tamanho numérico**  
  
     O *pointsize* campo da opção na fonte a **diálogo** instrução deve ser um valor de tamanho de ponto de inteiro.  
  
20. **Constante de caixa de diálogo numérico esperado**  
  
     Um **diálogo** instrução requer valores inteiros para o *x, y, largura*, e *altura* campos. Certifique-se de que esses valores sejam incluídos após o **diálogo** palavra-chave e que eles não sejam negativos.  
  
21. **A cadeia de caracteres esperada em STRINGTABLE**  
  
     Uma cadeia de caracteres é esperada depois de cada *IdentificaçãoDeSequênciaDeCaracteres* valor em uma **STRINGTABLE** instrução.  
  
22. **Cadeia de caracteres esperada ou comando constante accelerator**  
  
     O compilador de recurso não pôde determinar que tipo de chave está sendo configurado para o acelerador. O `event` campo o **ACELERADORES** instrução pode ser inválida.  
  
23. **Esperando o número de identificação**  
  
     Esperado um número para o `id` campo de uma instrução de controle no **diálogo** instrução. Verifique se você tem um número ou `#define` instrução para a ID do controle.  
  
24. **Esperando cadeia de caracteres entre aspas na classe de caixa de diálogo**  
  
     O `class` a opção de classe no campo de **diálogo** instrução deve ser um inteiro ou uma cadeia de caracteres entre aspas duplas.  
  
25. **Esperando cadeia de caracteres entre aspas no título da caixa de diálogo**  
  
     O `captiontext` campo da opção de legenda no **diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas.  
  
26. **Arquivo não encontrado: nome de arquivo**  
  
     O arquivo especificado na linha de comando do compilador de recurso não foi encontrado. Verifique se o arquivo foi movido para outro diretório e se o nome do arquivo ou caminho foi digitado corretamente. Arquivos são pesquisados para usar o **incluir** variável de ambiente ou a configuração de Visual Workbench, se disponível.  
  
27. **Os nomes de fonte devem ser números ordinais**  
  
     O *pointsize* campo na instrução de fonte deve ser um inteiro, não uma cadeia de caracteres.  
  
28. **Acelerador inválido**  
  
     Um `event` campo o **ACELERADORES** instrução não foi reconhecida ou era mais de dois caracteres.  
  
29. **Tipo de acelerador inválido (ASCII ou VIRTKEY)**  
  
     O `type` campo o **ACELERADORES** instrução deve conter o valor de ASCII ou VIRTKEY.  
  
30. **Caractere de controle inválido**  
  
     Um caractere de controle no **ACELERADORES** instrução é inválida. Um caractere de controle válido consiste em uma letra, um acento circunflexo (^) a seguir (somente).  
  
31. **Tipo de controle inválido**  
  
     Cada instrução de controle em um **diálogo** instrução deve ser um dos seguintes: caixa de seleção, caixa de COMBINAÇÃO, controle, CTEXT, DEFPUSHBUTTON, EDITTEXT, GROUPBOX, ícone, LISTBOX, LTEXT, botão de ação, RADIOBUTTON, RTEXT, barra de ROLAGEM. Verifique se essas instruções de controle estão escritas corretamente.  
  
32. **Tipo inválido**  
  
     O tipo de recurso não estava entre os tipos definidos no arquivo Windows. h.  
  
33. **Cadeia de caracteres de texto ou ordinal esperado no controle**  
  
     O *texto* campo de um **controle** instrução o **diálogo** instrução deve ser uma cadeia de caracteres de texto ou uma referência ordinal para o tipo de controle. Se usar um ordinal, certifique-se que você tem um `#define` instrução para o controle.  
  
34. **Parênteses incompatíveis**  
  
     Verifique se você fechou todos os parênteses de abertura **diálogo** instrução.  
  
35. **Valor inesperado em RCData**  
  
     O *dados brutos* valores no **RCDATA** instrução deve ser números inteiros ou cadeias de caracteres, cada um separado por uma vírgula. Certifique-se de não deixar uma vírgula ou omitir um sinal de aspas em torno de uma cadeia de caracteres.  
  
36. **Subtipo de menu desconhecido**  
  
     O *definição de item* campo o **MENU** só pode conter instrução **MENUITEM** e **pop-up** instruções.