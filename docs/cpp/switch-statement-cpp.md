---
title: Instrução switch (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- default_cpp
- switch_cpp
- case_cpp
dev_langs:
- C++
helpviewer_keywords:
- switch keyword [C++]
- case keyword [C++], in switch statements
- default keyword [C++]
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5cea2c7e4bff895f9ccabc044ed5b7f5ae506b32
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="switch-statement-c"></a>Instrução switch (C++)
Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
   switch ( init; expression )  
   case constant-expression : statement  
   [default  : statement]  
```  
  
## <a name="remarks"></a>Comentários  
 O *expressão* deve ser de um tipo integral ou de um tipo de classe para o qual há uma conversão não ambígua para tipo integral. Promoção de integral é executada conforme descrito em [conversões padrão](standard-conversions.md).  
  
 O `switch` corpo da instrução consiste em uma série de **caso** rótulos e um opcional **padrão** rótulo. Não há duas expressões de constantes em **caso** instruções podem ser avaliadas como o mesmo valor. O **padrão** rótulo pode aparecer apenas uma vez. As instruções rotuladas não são requisitos sintáticos, mas a instrução `switch` fica sem sentido sem elas.   A instrução default não precisa vir no final; ela pode aparecer em qualquer lugar no corpo da instrução switch. Um rótulo case ou default só pode aparecer dentro de uma instrução switch.  
  
 O *expressão constante* em cada **caso** rótulo é convertido para o tipo de *expressão* e comparada com *expressão* para igualdade. O controle passará para a instrução cuja **caso** *expressão constante* corresponde ao valor do *expressão*. O comportamento resultante é mostrado na tabela a seguir.  
  
### <a name="switch-statement-behavior"></a>Comportamento da instrução switch  
  
|Condição|Ação|  
|---------------|------------|  
|O valor convertido corresponde ao da expressão de controle promovida.|O controle é transferido para a instrução após esse rótulo.|  
|Nenhuma das constantes corresponder as constantes no **caso** rótulos; um **padrão** rótulo está presente.|O controle é transferido para o **padrão** rótulo.|  
|Nenhuma das constantes corresponder as constantes no **caso** rótulos; **padrão** rótulo não está presente.|O controle é transferido para a instrução após a instrução `switch`.|  
  
 Se uma expressão de correspondência for encontrada, o controle não é impedido por subsequentes **caso** ou **padrão** rótulos. O [quebra](../cpp/break-statement-cpp.md) instrução é usada para interromper a execução e transfere o controle para a instrução após a `switch` instrução. Sem um **quebra** instrução, cada instrução da correspondentes **caso** rótulo ao final do `switch`, incluindo o **padrão**, é executado. Por exemplo:  
  
```  
// switch_statement1.cpp  
#include <stdio.h>  
  
int main() {  
   char *buffer = "Any character stream";  
   int capa, lettera, nota;  
   char c;  
   capa = lettera = nota = 0;  
  
   while ( c = *buffer++ )   // Walks buffer until NULL  
   {  
      switch ( c )  
      {  
         case 'A':  
            capa++;  
            break;  
         case 'a':  
            lettera++;  
            break;  
         default:  
            nota++;  
      }  
   }  
   printf_s( "\nUppercase a: %d\nLowercase a: %d\nTotal: %d\n",  
      capa, lettera, (capa + lettera + nota) );  
}  
```  
  
 No exemplo acima, `capa` será incrementado se `c` for `A` maiúsculo. A instrução `break` após `capa++` termina a execução do corpo da instrução `switch` e passa o controle para o loop `while`. Sem o `break` instrução, execução "caiu por meio de" para a próxima instrução rotulada, para que `lettera` e `nota` também deve ser incrementado. A instrução `break` para `case 'a'` cumpre finalidade semelhante. Se `c` for `a` minúsculo, `lettera` será incrementado e a instrução `break` terminará o corpo da instrução `switch`. Se `c` não for `a` nem `A`, a instrução `default` será executada.  

 **Visual Studio 2017 e posterior:** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo é especificado o padrão C++ 17. Ele pode ser usado em um `switch` instrução como uma dica para o compilador (ou para qualquer pessoa que o código de leitura) destina-se esse comportamento leva a algo. O compilador do Visual C++ no momento não avisa sobre o comportamento de fallthrough para que este atributo não tem nenhum comportamento de compilador efeito. Observe que o atributo é aplicado a uma instrução vazia dentro da instrução rotulada; em outras palavras, o ponto e vírgula é necessário.

```cpp
int main()
{
    int n = 5;
    switch (n)
    {

    case 1:
        a();
        break;
    case 2:
        b();
        d();
        [[fallthrough]]; // I meant to do this!
    case 3:
        c();
        break;
    default:
        d();
        break;
    }

    return 0;
}
```

 **Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): uma instrução switch pode introduzir e inicializar uma variável cujo escopo é limitado para o bloco da instrução switch:

```cpp
 switch (Gadget gadget(args); auto s = gadget.get_status())
        {
        case status::good:
            gadget.zip();
            break;
        case status::bad:
            throw BadGadget();
        };
```

 Um bloco interno de uma instrução `switch` pode conter definições com inicializações, desde que elas sejam acessíveis, isto é, não sejam ignoradas por todos os caminhos de execução possíveis. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:  
  
```cpp  
// switch_statement2.cpp  
// C2360 expected  
#include <iostream>  
using namespace std;  
int main(int argc, char *argv[])  
{  
   switch( tolower( *argv[1] ) )  
   {  
       // Error. Unreachable declaration.  
       char szChEntered[] = "Character entered was: ";  
  
   case 'a' :  
       {  
       // Declaration of szChEntered OK. Local scope.  
       char szChEntered[] = "Character entered was: ";  
       cout << szChEntered << "a\n";  
       }  
       break;  
  
   case 'b' :  
       // Value of szChEntered undefined.  
       cout << szChEntered << "b\n";  
       break;  
  
   default:  
       // Value of szChEntered undefined.  
       cout << szChEntered << "neither a nor b\n";  
       break;  
   }  
}  
```  
  
 Uma instrução `switch` pode estar aninhada. Nesses casos, **caso** ou **padrão** rótulos associar com o mais próximo `switch` instrução que inclui-los.  

 
## <a name="microsoft-specific"></a>Específico da Microsoft  
 O Microsoft C não limita o número de valores de case em uma instrução `switch`. O número é limitado somente pela memória disponível. O ANSI C requer que pelo menos 257 rótulos case sejam permitidos em uma instrução `switch`.  
  
 O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador desabilitar essas extensões.  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 