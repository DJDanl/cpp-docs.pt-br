---
title: "Instru&#231;&#227;o switch (C) | Microsoft Docs"
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
  - "switch"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "palavra-chave switch [C]"
ms.assetid: fbede014-23bd-4ab1-8094-c8d9d9cb963a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o switch (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As instruções `switch` e **case** ajudam a controlar operações complexas condicionais e de ramificação.  A instrução `switch` transfere o controle para uma instrução dentro do corpo.  
  
## Sintaxe  
 *selection\-statement*:  
 **switch \(** *expression* **\)** *statement*  
  
 *labeled\-statement*:  
 **case**  *constant\-expression*  **:**  *statement*  
  
 **default :**  *statement*  
  
 O controle passa para a instrução cuja *expressão constante* de **case** corresponde ao valor de **switch \(** *expressão* **\)**.  A instrução `switch` pode incluir qualquer número de instâncias de **case**, mas duas constantes de case não podem ter a mesma instrução `switch` com o mesmo valor.  A execução do corpo da instrução começa na instrução selecionada e continua até o final do corpo ou até uma instrução **break** transfira o controle para fora do corpo.  
  
 O uso da instrução `switch` geralmente tem essa aparência:  
  
 `switch` \( *expressão* \)  
  
 **{**  
  
 *declarações*  
  
 .  
  
 .  
  
 .  
  
 **case** *expressão constante* **:**  
  
 *instruções executadas se a expressão for igual a*  
  
 *valor da expressão constante*  
  
 .  
  
 .  
  
 .  
  
 **break;**  
  
 **padrão:**  
  
 *instruções executadas se a expressão não for igual a*  
  
 *qualquer expressão constante de caso*  
  
 **}**  
  
 Você pode usar a instrução **break** para encerrar o processamento de um caso específico dentro da instrução `switch` e para ramificar ao final da instrução `switch`.  Sem **break**, o programa continua nos próximos casos, executando as instruções **break** ou até que o final da instrução seja atingido.  Em algumas situações, essa continuação pode ser desejável.  
  
 A instrução **default** é executada se nenhuma *expressão constante* **case**for igual ao valor de **switch \(*expressão*\)**.  Se a instrução **default** for omitida e nenhuma correspondência de **case** for encontrada, nenhuma das instruções no corpo de `switch` é executada.  Pode haver no máximo uma instrução **default**.  A instrução **default** não precisa chegar ao final; ela pode aparecer em qualquer local do corpora da declaração `switch`.  Um rótulo **case** ou **default** pode ser exibido apenas dentro de uma instrução `switch`.  
  
 O tipo da *expressão* `switch` e *expressão constante* **case** deve ser um inteiro.  O valor de cada *expressão constante* de **case** deve ser exclusivo dentro do corpo da instrução.  
  
 Os rótulos **case** e **default** do corpo da instrução `switch` são significativos apenas no teste inicial que determina onde a execução começa no corpo da instrução.  As instruções de alternância podem ser aninhadas.  Todas as variáveis estáticas são inicializadas antes da execução em qualquer `switch` instrução.  
  
> [!NOTE]
>  As declarações podem aparecer no início da instrução composta que forma o corpo de `switch`, mas as inicializações incluídas nas declarações não serão executadas.  A instrução `switch` transfere o controle diretamente para uma instrução executável dentro do corpo, ignorando as linhas que contêm inicializações.  
  
 Os exemplos a seguir ilustram as instruções `switch`:  
  
```  
switch( c )   
{  
    case 'A':  
        capa++;  
    case 'a':  
        lettera++;  
    default :  
        total++;  
}  
```  
  
 Neste exemplo, as três instruções do corpo de `switch` são executadas se `c` é igual a `'A'`, contanto que uma instrução **break** não apareça antes dos seguintes casos.  O controle de execução é transferido para a primeira instrução \(`capa++;`\) e continua em ordem pelo restante do corpo.  Se `c` é igual a `'a'`, `lettera` e `total` são incrementados.  Apenas `total` é incrementado se `c` não é igual a `'A'` ou a `'a'`.  
  
```  
switch( i )   
{  
    case -1:  
        n++;  
        break;  
    case 0 :  
        z++;  
        break;  
    case 1 :  
        p++;  
        break;  
}  
```  
  
 Neste exemplo, uma instrução **break** segue cada instrução do corpo de `switch`.  A instrução **break** força uma saída do corpo da instrução depois que uma instrução é executada.  Se `i` for igual a –1, apenas `n` é incrementado.  O **break** que segue a instrução `n++;` faz com que o controle de execução seja passado para fora do corpo da instrução, ignorando as instruções restantes.  Da mesma forma, se `i` é igual a 0, somente `z` será incrementado; se `i` é igual a 1, somente `p` será incrementado.  A instrução de **break** final não é estritamente necessária, pois o controle para fora do corpo no final da instrução composta, mas é incluído para manter a consistência.  
  
 Uma única instrução pode levar vários rótulos de **case**, conforme mostrado no exemplo a seguir:  
  
```  
case 'a' :  
case 'b' :  
case 'c' :  
case 'd' :  
case 'e' :  
case 'f' :  hexcvt(c);  
```  
  
 Nesse exemplo, se a *expressão constante* for igual a qualquer letra entre `'a'` e `'f'`, a função `hexcvt` é chamada.  
  
 **Específico da Microsoft**  
  
 O Microsoft C não limita o número de valores de case em uma instrução `switch`.  O número é limitado somente pela memória disponível.  O ANSI C requer que pelo menos 257 rótulos case sejam permitidos em uma instrução `switch`.  
  
 O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas.  Use a opção de compilador \/Za para desativar essas extensões.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Instrução switch \(C\+\+\)](../cpp/switch-statement-cpp.md)