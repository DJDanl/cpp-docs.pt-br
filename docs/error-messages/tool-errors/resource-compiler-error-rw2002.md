---
title: RW2002 de erro do compilador de recurso | Documentos do Microsoft
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
caps.latest.revision: 6
author: corob-msft
ms.author: corob
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
ms.openlocfilehash: 0a47b3c8223ccb2d0bf273707c2f04ef382c1dce
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="resource-compiler-error-rw2002"></a>Erro RW2002 (compilador de recurso)
Erro de análise  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  **Tipo de acelerador necessária (ASCII ou VIRTKEY)**  
  
     O `type` campo o **ACELERADORES** instrução deve conter o valor de ASCII ou VIRTKEY.  
  
2.  **INÍCIO esperado na tabela de teclas aceleradoras**  
  
     O **BEGIN** palavra-chave deve seguir imediatamente o **ACELERADORES** palavra-chave.  
  
3.  **INÍCIO esperado na caixa de diálogo**  
  
     O **BEGIN** palavra-chave deve seguir imediatamente o **caixa de diálogo** palavra-chave.  
  
4.  **INÍCIO esperado no menu**  
  
     O **BEGIN** palavra-chave deve seguir imediatamente o **MENU** palavra-chave.  
  
5.  **INÍCIO esperado em RCData**  
  
     O **BEGIN** palavra-chave deve seguir imediatamente o **RCDATA** palavra-chave.  
  
6.  **COMEÇAR a palavra-chave esperado na tabela de cadeia de caracteres**  
  
     O **BEGIN** palavra-chave deve seguir imediatamente o **STRINGTABLE** palavra-chave.  
  
7.  **Não é possível reutilizar a constantes de cadeia de caracteres**  
  
     Você está usando o mesmo valor duas vezes em uma **STRINGTABLE** instrução. Verifique se que você está misturando não sobrepostos valores decimais e hexadecimais. Cada ID em um **STRINGTABLE** deve ser exclusivo. Para máxima eficiência, use constantes contíguas com início em um múltiplo de 16.  
  
8.  **Caractere fora do intervalo de controle [^ A - ^ Z]**  
  
     Um caractere de controle no **ACELERADORES** instrução é inválida. O caractere após o cursor (**^**) deve estar entre A e Z, inclusive.  
  
9. **Menus vazios não permitidos**  
  
     Um **final** palavra-chave aparece antes de quaisquer itens de menu são definidos na **MENU** instrução. O compilador de recurso não permite que menus vazias. Verifique se você não tem qualquer aspas abertas dentro do **MENU** instrução.  
  
10. **TÉRMINO esperado na caixa de diálogo**  
  
     O **final** palavra-chave deve ocorrer no final de uma **caixa de diálogo** instrução. Verifique se há sem aspas de abertura à esquerda da instrução anterior.  
  
11. **TÉRMINO esperado no menu**  
  
     O **final** palavra-chave deve vir no final de uma **MENU** instrução. Verifique se você não tem qualquer aspas abertas ou um par incompatível de **BEGIN** e **final** instruções.  
  
12. **Vírgula esperada no Acelerador de tabela**  
  
     O compilador de recurso exige uma vírgula entre o `event` e *idvalue* campos de **ACELERADORES** instrução.  
  
13. **Nome da classe de controle esperado**  
  
     O `class` campo de um **controle** instrução no **caixa de diálogo** instrução deve ser um dos seguintes tipos: botão, COMBOBOX, editar, LISTBOX, barra de ROLAGEM, estático, ou definido pelo usuário. Verifique se que a classe está escrita corretamente.  
  
14. **Esperado um nome de face da fonte**  
  
     O *face de tipos* a opção de fonte no campo de **caixa de diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas. Este campo especifica o nome de uma fonte.  
  
15. **Valor de ID esperado para menuitem**  
  
     O **MENU** instrução deve conter um *menuID* campo, que especifica o nome ou o número que identifica o recurso do menu.  
  
16. **Cadeia de caracteres de menu esperado**  
  
     Cada **MENUITEM** e **pop-up** instrução deve conter um *texto* campo, que é uma cadeia de caracteres entre aspas duplas que especifica o nome do menu pop-up ou de item de menu. A **MENUITEM SEPARADOR** instrução não exige nenhuma cadeia de caracteres entre aspas.  
  
17. **Valor do comando numérico esperado**  
  
     O compilador de recurso estava esperando um numérico *idvalue* campo o **ACELERADORES** instrução. Certifique-se de que você usou um `#define` constante para especificar o valor e que a constante está escrita corretamente.  
  
18. **Esperado constante numérica na tabela de cadeia de caracteres**  
  
     Uma constante numérica, definido em uma `#define` instrução, deve seguir imediatamente o **começar** palavra-chave em uma **STRINGTABLE** instrução.  
  
19. **Tamanho de ponto numérico esperado**  
  
     O *pointsize* a opção de fonte no campo de **diálogo** instrução deve ser um inteiro de tamanho de ponto.  
  
20. **Constante de diálogo numérico esperado**  
  
     A **caixa de diálogo** instrução requer valores inteiros para o *x, y, largura*, e *altura* campos. Certifique-se de que esses valores são incluídos após o **caixa de diálogo** palavra-chave e que eles não sejam negativos.  
  
21. **Cadeia de caracteres esperada em STRINGTABLE**  
  
     Uma cadeia de caracteres é esperada após cada *IdentificaçãoDeSequênciaDeCaracteres* valor em uma **STRINGTABLE** instrução.  
  
22. **Cadeia de caracteres esperada ou o comando de aceleração constante**  
  
     O compilador de recurso não pôde determinar que tipo de chave está sendo configurado para o acelerador. O `event` campo o **ACELERADORES** instrução pode ser inválida.  
  
23. **Esperando o número de identificação**  
  
     Esperado um número para o `id` campo de uma instrução de controle no **caixa de diálogo** instrução. Verifique se você tem um número ou `#define` instrução para a ID do controle.  
  
24. **Esperando a cadeia de caracteres entre aspas na classe de caixa de diálogo**  
  
     O `class` a opção de classe no campo de **caixa de diálogo** instrução deve ser um inteiro ou uma cadeia de caracteres entre aspas duplas.  
  
25. **Esperando a cadeia de caracteres entre aspas no título da caixa de diálogo**  
  
     O `captiontext` campo da opção legenda a **caixa de diálogo** instrução deve ser uma cadeia de caracteres ASCII entre aspas duplas.  
  
26. **Arquivo não encontrado: filename**  
  
     O arquivo especificado na linha de comando de compilador de recurso não foi encontrado. Verifique se o arquivo foi movido para outro diretório e se o nome do arquivo ou o caminho foi digitado corretamente. Arquivos são pesquisados para usar o **incluir** variável de ambiente ou a configuração da Bancada de trabalho Visual, se disponível.  
  
27. **Os nomes de fonte devem ser números ordinais**  
  
     O *pointsize* campo na instrução de fonte deve ser um inteiro, não uma cadeia de caracteres.  
  
28. **Aceleração é inválido**  
  
     Um `event` campo o **ACELERADORES** instrução não foi reconhecida ou era mais de dois caracteres.  
  
29. **Tipo de acelerador inválido (ASCII ou VIRTKEY)**  
  
     O `type` campo o **ACELERADORES** instrução deve conter o valor de ASCII ou VIRTKEY.  
  
30. **Caractere de controle inválido**  
  
     Um caractere de controle no **ACELERADORES** instrução é inválida. Um caractere de controle válido consiste em uma letra (apenas) após um acento circunflexo (^).  
  
31. **Tipo de controle inválido**  
  
     Cada instrução de controle em uma **caixa de diálogo** instrução deve ser um dos seguintes: caixa de seleção, caixa de COMBINAÇÃO, controle, CTEXT, DEFPUSHBUTTON, EDITTEXT, GROUPBOX, ícone, LISTBOX, LTEXT, PUSHBUTTON, RADIOBUTTON, RTEXT, barra de ROLAGEM. Verifique se essas instruções de controle estão escritas corretamente.  
  
32. **Tipo inválido**  
  
     O tipo de recurso não estava entre os tipos definidos no arquivo do Windows. h.  
  
33. **Cadeia de caracteres de texto ou ordinal esperado no controle**  
  
     O *texto* campo de um **controle** instrução o **caixa de diálogo** instrução deve ser uma cadeia de caracteres de texto ou uma referência ordinal para o tipo de controle. Se usar um ordinal, verifique se você tem um `#define` instrução para o controle.  
  
34. **Parênteses incompatíveis**  
  
     Verifique se você fechou todos os parênteses de abertura **caixa de diálogo** instrução.  
  
35. **Valor inesperado em RCData**  
  
     O *dados brutos* valores a **RCDATA** instrução deve ser números inteiros ou cadeias de caracteres, cada um separado por uma vírgula. Verifique se você não deixar uma vírgula ou omitir um sinal de aspas ao redor de uma cadeia de caracteres.  
  
36. **Subtipo de menu desconhecido**  
  
     O *definição de item* campo o **MENU** instrução só pode conter **MENUITEM** e **pop-up** instruções.
