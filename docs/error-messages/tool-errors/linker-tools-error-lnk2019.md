---
title: Ferramentas de vinculador LNK2019 erro | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- LNK2019
dev_langs:
- C++
helpviewer_keywords:
- nochkclr.obj
- LNK2019
- _check_commonlanguageruntime_version
ms.assetid: 4392be92-195c-4eb2-bd4d-49cfac3ca291
caps.latest.revision: 39
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 6cad5222fb0d97594d5b13b5cf8903eb2934ee88
ms.openlocfilehash: 86b43f2688b6e1dbfb39dfec681ca9adafd2c093
ms.lasthandoff: 02/25/2017

---
# <a name="linker-tools-error-lnk2019"></a>Erro das Ferramentas de Vinculador LNK2019
símbolo externo não resolvido 'symbol' referenciada na função 'function'  
  
 O vinculador não foi possível localizar uma definição de símbolo externo "`symbol`"usada na função"`function`".  
  
 Há muitos problemas que podem causar esse erro. Este tópico o ajudará a identificar a causa e encontrar uma solução.  
  
 A *símbolo* é o nome que o compilador usa para uma função ou variável global. Um *símbolo externo* é o nome usado para fazer referência a um símbolo que é definido em um arquivo de origem ou de objeto diferente. O vinculador deve *resolver*, ou localizar a definição para o símbolo externo para cada função ou variável global usado por cada arquivo compilado quando ele está vinculado em um aplicativo ou DLL. Se o vinculador não pode localizar uma definição de correspondência para um símbolo externo em qualquer um dos arquivos vinculados, ele gera LNK2019.  
  
 Esse erro pode ocorrer se o arquivo de biblioteca ou objeto que tem a definição de um símbolo não está incluído na compilação. Ele também pode ocorrer se o vinculador procura o nome do símbolo não coincide com o nome do símbolo no arquivo de biblioteca ou objeto que o define. Isso pode acontecer se o nome no código de chamada está incorreto, usa maiusculas/minúsculas diferente, usa uma convenção de chamada diferente ou especifica parâmetros diferentes.  
  
 O código que usa a vinculação C++ usa [decoração de nome](../../error-messages/tool-errors/name-decoration.md), também conhecido como *-desconfiguração do nome*, para codificar informações extras sobre uma variável ou tipo e no nome do símbolo convenção de chamada da função. O *nome decorado* é o nome que o vinculador procura para resolver símbolos externos. Como o tipo de informação se torna parte do nome decorado do símbolo, LNK2019 pode acontecer se a declaração do símbolo externo onde ele é usado não coincide com a declaração do símbolo onde ele está definido. Para ajudá-lo a encontrar a causa do erro, a mensagem de erro mostra os dois o "nome amigável," o nome usado no código-fonte e o nome decorado (entre parênteses) para o símbolo externo não resolvido. Você não precisa saber como traduzir o nome decorado para poder compará-lo com outros nomes decorados.  
  
 **Problemas comuns**  
  
 Aqui estão alguns problemas comuns que causam LNK2019:  
  
-   **O arquivo de objeto ou a biblioteca que contém a definição do símbolo não está vinculada.** No Visual Studio, verifique se o arquivo de origem que contém a definição é criado e vinculado como parte do seu projeto. Na linha de comando, verifique se que o arquivo de origem que contém a definição é compilado, e que o arquivo de objeto resultante é incluído na lista de arquivos para vincular.  
  
-   **A declaração do símbolo não foi digitada o mesmo que a definição do símbolo.** Verifique se a grafia correta e capitalização é usado na declaração e a definição e onde quer que o símbolo é usado ou chamado.  
  
-   **Uma função é usada, mas o tipo ou o número de parâmetros não correspondem a definição da função.** A declaração de função deve corresponder a definição. Verifique se a chamada de função corresponde a declaração e a declaração corresponde à definição. Código que chama as funções de modelo também deve ter declarações de função de modelo que incluem os mesmos parâmetros de modelo que a definição de correspondência. Para obter um exemplo de uma incompatibilidade de declaração de modelo, consulte o exemplo LNK2019e.cpp na seção exemplos.  
  
-   **Uma função ou variável é declarada mas não definido.** Isso geralmente significa uma declaração existe em um arquivo de cabeçalho, mas nenhuma definição correspondente é implementada. Para funções de membro ou membros de dados estáticos, a implementação deve incluir o seletor de escopo de classe. Para obter um exemplo, consulte [ausente corpo da função ou variável](../../error-messages/tool-errors/missing-function-body-or-variable.md).  
  
-   **A convenção de chamada é diferente entre a declaração de função e a definição de função.** Convenções de chamada ([cdecl](../../cpp/cdecl.md), [stdcall](../../cpp/stdcall.md), [fastcall](../../cpp/fastcall.md), ou [vectorcall](../../cpp/vectorcall.md)) são codificados como parte do nome decorado. Verifique se a convenção de chamada é o mesmo.  
  
-   **Um símbolo é definido em um arquivo de C, mas declarado sem usar extern "C" em um arquivo C++.** Símbolos definidos em um arquivo que é compilado como C tem diferentes nomes decorados símbolos declarado em um arquivo de C++, a menos que você use um [extern "C"](../../cpp/using-extern-to-specify-linkage.md) modificador. Verifique se a declaração corresponde a vinculação de compilação para cada símbolo.  
  
     Da mesma forma, se você definir um símbolo em um arquivo de C++ que será usado por um programa em C, use `extern "C"` na definição.  
  
-   **Um símbolo é definido como estático e posteriormente referenciado fora do arquivo.** No C++, ao contrário de C, [constantes globais](../../error-messages/tool-errors/global-constants-in-cpp.md) ter `static` vinculação. Para contornar essa limitação, você pode incluir o `const` inicializações em um cabeçalho de arquivo e incluem esse cabeçalho nos arquivos. cpp, ou você pode fazer a variável não constante e usar uma referência constante para acessá-lo.  
  
-   **Um membro estático de uma classe não está definido.** Um membro de classe estática deve ter uma definição exclusiva ou violar a regra de definição de um. Um membro de classe estática que não pode ser definidas embutidas deve ser definido em um arquivo de origem usando o nome totalmente qualificado. Se ele não está definido em todos os, o vinculador gera LNK2019.  
  
-   **Uma dependência de compilação só é definida como uma dependência de projeto na solução.** Em versões anteriores do [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)], esse nível de dependência foi suficiente. No entanto, começando com o Visual Studio 2010, [!INCLUDE[vsprvs](../../assembler/masm/includes/vsprvs_md.md)] requer um [referência projeto a projeto](/visualstudio/ide/managing-references-in-a-project). Se seu projeto não tem uma referência de projeto para projeto, você receberá esse erro do vinculador. Adicione uma referência de projeto para o projeto para corrigi-lo.  
  
-   **Criar um aplicativo de console usando as configurações para um aplicativo do Windows**. Se a mensagem de erro é semelhante ao **símbolo externo não resolvido WinMain referenciada na função**`function_name`, link usando **/Subsystem: console** em vez de **/SUBSYSTEM:WINDOWS**. Para obter mais informações sobre essa configuração e para obter instruções sobre como definir essa propriedade no Visual Studio, consulte [/SUBSYSTEM (especificar subsistema)](../../build/reference/subsystem-specify-subsystem.md).  
  
-   **Você pode usar opções do compilador diferentes para a função inlining nos arquivos de origem diferentes.** Usando funções embutidas definidas em arquivos. cpp e combinação de opções do compilador inlining função nos arquivos de origem diferentes pode causar LNK2019. Para obter mais informações, consulte [problemas de Inlining de função](../../error-messages/tool-errors/function-inlining-problems.md).  
  
-   **Você pode usar variáveis automáticas fora de seu escopo.** Variáveis automáticas (escopo da função) podem ser usados somente no escopo de função. Essas variáveis não podem ser declaradas `extern` e usado em outros arquivos de origem. Para obter um exemplo, consulte [as variáveis automáticas (escopo da função)](../../error-messages/tool-errors/automatic-function-scope-variables.md).  
  
-   **Chamar funções instrinsic ou passar tipos de argumento para as funções intrínsecas que não têm suporte em sua arquitetura de destino.** Por exemplo, se você usar um AVX2 intrínseco, mas não especificar o [avx2](../../build/reference/arch-x86.md) opção de compilador, o compilador pressupõe que o intrínseco é uma função externa. Em vez de gerar uma instrução embutido, o compilador gera uma chamada para um símbolo externo com o mesmo nome que o intrínseco. Quando o vinculador tenta localizar a definição dessa função ausente, ele gera LNK2019. Verifique se que você use apenas intrínsecos e tipos compatíveis com sua arquitetura de destino.  
  
-   **Misturar código que usa wchar_t nativo com código não.** Trabalho de conformidade de linguagem C++ que foi feito no Visual C++ 2005 fez `wchar_t` um tipo nativo por padrão. Você deve usar o [/Zc:wchar_t-](../../build/reference/zc-wchar-t-wchar-t-is-native-type.md) opção de compilador para gerar código compatível com os arquivos de biblioteca e objeto compilados usando versões anteriores do Visual C++. Se nem todos os arquivos foram compilados usando o mesmo **/ZC:** configurações, digite referências podem não ser resolvidas em tipos compatíveis. Verifique `wchar_t` tipos em todos os arquivos de biblioteca e objeto são compatíveis, atualizando os tipos que são usados ou usando consistente **/ZC:** configurações quando você compilar.  
  
 Para obter mais informações sobre as possíveis causas e soluções para LNK2019, consulte a pergunta de estouro de pilha [o que é um erro de símbolo externo indefinido referência/não resolvidos e como corrigi-lo?](http://stackoverflow.com/q/12573816/2002113).  
  
 **Ferramentas de diagnóstico**  
  
 Pode ser difícil saber por que o vinculador não encontrar uma definição de símbolo específico. Geralmente, o problema é que você não incluiu o código em sua compilação ou criar diferentes opções de compilação decorados nomes de símbolos externos. Há várias ferramentas e opções que podem ajudar a diagnosticarem um erro de LNK2019.  
  
-   O [/verbose](../../build/reference/verbose-print-progress-messages.md) opção de vinculador pode ajudá-lo a determinar quais arquivos as vinculador de referências. Isso pode ajudá-lo a verificar se o arquivo que contém a definição do símbolo é incluído em sua compilação.  
  
-   O [/EXPORTA](../../build/reference/dash-exports.md) e [/símbolos](../../build/reference/symbols.md) opções do utilitário DUMPBIN podem ajudá-lo a descobrir quais símbolos são definidos em seus arquivos. dll e objeto ou biblioteca. Verifique se que o arquivo decorado nomes correspondem ao que decorado nomeia o vinculador procura.  
  
-   O utilitário UNDNAME pode mostrar o símbolo externo não decorado equivalente para um nome decorado.  
  
 **Exemplos**  
  
 Aqui estão alguns exemplos de código que causa um erro LNK2019, junto com informações sobre como corrigir o erro.  
  
 **Um símbolo é declarado mas não definido**  
  
 O exemplo a seguir gera LNK2019 porque um símbolo externo é declarado mas não definido:  
  
```cpp  
// LNK2019.cpp  
// Compile by using: cl /EHsc LNK2019.cpp  
// LNK2019 expected  
extern char B[100];   // B is not available to the linker  
int main() {  
   B[0] = ' ';   // LNK2019  
}  
```  
  
 Aqui está outro exemplo:  
  
```cpp  
// LNK2019c.cpp  
// Compile by using: cl /EHsc LNK2019c.cpp  
// LNK2019 expected  
extern int i;  
extern void g();  
void f() {  
   i++;  
   g();  
}  
int main() {}  
```  
  
 Se `i` e `g` não são definidos em um dos arquivos na compilação, o vinculador gera LNK2019. Você pode corrigir os erros, incluindo o arquivo de código fonte que contém as definições como parte da compilação. Como alternativa, você pode passar para o vinculador. obj arquivos ou. lib que contém as definições.  
  
 **Um membro de dados estáticos é declarado mas não definido**  
  
 LNK2019 também pode ocorrer quando um membro de dados estáticos é declarado mas não definido. O exemplo a seguir gera LNK2019 e mostra como corrigi-lo.  
  
```cpp  
// LNK2019b.cpp  
// Compile by using: cl /EHsc LNK2019b.cpp  
// LNK2019 expected  
struct C {  
   static int s;  
};  
  
// Uncomment the following line to fix the error.  
// int C::s;  
  
int main() {  
   C c;  
   C::s = 1;  
}  
```  
  
 **Parâmetros de declaração não corresponde à definição da**  
  
 Código que chama as funções de modelo deve ter correspondência de declarações de função do modelo. Declarações devem incluir os mesmos parâmetros de modelo que a definição. O exemplo a seguir gera LNK2019 um operador definido pelo usuário e mostra como corrigi-lo.  
  
```cpp  
// LNK2019e.cpp  
// compile by using: cl /EHsc LNK2019e.cpp  
// LNK2019 expected  
#include <iostream>  
using namespace std;  
  
template<class T> class   
Test {  
   // The operator<< declaration does not match the definition below:  
   friend ostream& operator<<(ostream&, Test&);  
   // To fix, replace the line above with the following:  
   // template<typename T> friend ostream& operator<<(ostream&, Test<T>&);  
};  
  
template<typename T>  
ostream& operator<<(ostream& os, Test<T>& tt) {  
   return os;  
}  
  
int main() {  
   Test<int> t;  
   cout << "Test: " << t << endl;   // LNK2019 unresolved external  
}  
```  
  
 **Definições de tipo wchar_t inconsistente**  
  
 O exemplo a seguir cria uma DLL que tem uma exportação que usa `WCHAR`, que resolve para `wchar_t`.  
  
```cpp  
// LNK2019g.cpp  
// compile with: cl /EHsc /LD LNK2019g.cpp  
#include "windows.h"  
// WCHAR resolves to wchar_t  
__declspec(dllexport) void func(WCHAR*) {}  
```  
  
 O exemplo a seguir usa a DLL no exemplo anterior e gera LNK2019 porque os tipos unsigned short * e WCHAR\* não são iguais.  
  
```cpp  
// LNK2019h.cpp  
// compile by using: cl /EHsc LNK2019h LNK2019g.lib  
// LNK2019 expected  
__declspec(dllimport) void func(unsigned short*);  
  
int main() {  
   func(0);  
}  
```  
  
 Para resolver esse erro, altere `unsigned short` para `wchar_t` ou `WCHAR`, ou compile LNK2019g.cpp usando **/Zc:wchar_t-**.
