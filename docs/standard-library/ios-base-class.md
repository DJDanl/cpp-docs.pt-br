---
title: Classe ios_base | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- xiosbase/std::ios_base
- ios/std::ios_base::event_callback
- xiosbase/std::ios_base::fmtflags
- xiosbase/std::ios_base::iostate
- xiosbase/std::ios_base::openmode
- xiosbase/std::ios_base::seekdir
- xiosbase/std::ios_base::event
- xiosbase/std::ios_base::adjustfield
- xiosbase/std::ios_base::app
- xiosbase/std::ios_base::ate
- xiosbase/std::ios_base::badbit
- xiosbase/std::ios_base::basefield
- xiosbase/std::ios_base::beg
- xiosbase/std::ios_base::binary
- xiosbase/std::ios_base::boolalpha
- xiosbase/std::ios_base::cur
- xiosbase/std::ios_base::dec
- xiosbase/std::ios_base::end
- xiosbase/std::ios_base::eofbit
- xiosbase/std::ios_base::failbit
- xiosbase/std::ios_base::fixed
- xiosbase/std::ios_base::floatfield
- xiosbase/std::ios_base::goodbit
- xiosbase/std::ios_base::hex
- xiosbase/std::ios_base::in
- xiosbase/std::ios_base::internal
- xiosbase/std::ios_base::left
- xiosbase/std::ios_base::oct
- xiosbase/std::ios_base::out
- xiosbase/std::ios_base::right
- xiosbase/std::ios_base::scientific
- xiosbase/std::ios_base::showbase
- xiosbase/std::ios_base::showpoint
- xiosbase/std::ios_base::showpos
- xiosbase/std::ios_base::skipws
- xiosbase/std::ios_base::trunc
- xiosbase/std::ios_base::unitbuf
- xiosbase/std::ios_base::uppercase
- xiosbase/std::ios_base::failure
- xiosbase/std::ios_base::flags
- xiosbase/std::ios_base::getloc
- xiosbase/std::ios_base::imbue
- xiosbase/std::ios_base::Init
- xiosbase/std::ios_base::iword
- xiosbase/std::ios_base::precision
- xiosbase/std::ios_base::pword
- ios/std::ios_base::register_callback
- xiosbase/std::ios_base::setf
- xiosbase/std::ios_base::sync_with_stdio
- xiosbase/std::ios_base::unsetf
- xiosbase/std::ios_base::width
- xiosbase/std::ios_base::xalloc
dev_langs: C++
helpviewer_keywords:
- std::ios_base [C++]
- std::ios_base [C++], event_callback
- std::ios_base [C++], fmtflags
- std::ios_base [C++], iostate
- std::ios_base [C++], openmode
- std::ios_base [C++], seekdir
- std::ios_base [C++], event
- std::ios_base [C++], adjustfield
- std::ios_base [C++], app
- std::ios_base [C++], ate
- std::ios_base [C++], badbit
- std::ios_base [C++], basefield
- std::ios_base [C++], beg
- std::ios_base [C++], binary
- std::ios_base [C++], boolalpha
- std::ios_base [C++], cur
- std::ios_base [C++], dec
- std::ios_base [C++], end
- std::ios_base [C++], eofbit
- std::ios_base [C++], failbit
- std::ios_base [C++], fixed
- std::ios_base [C++], floatfield
- std::ios_base [C++], goodbit
- std::ios_base [C++], hex
- std::ios_base [C++], in
- std::ios_base [C++], internal
- std::ios_base [C++], left
- std::ios_base [C++], oct
- std::ios_base [C++], out
- std::ios_base [C++], right
- std::ios_base [C++], scientific
- std::ios_base [C++], showbase
- std::ios_base [C++], showpoint
- std::ios_base [C++], showpos
- std::ios_base [C++], skipws
- std::ios_base [C++], trunc
- std::ios_base [C++], unitbuf
- std::ios_base [C++], uppercase
- std::ios_base [C++], failure
- std::ios_base [C++], flags
- std::ios_base [C++], getloc
- std::ios_base [C++], imbue
- std::ios_base [C++], Init
- std::ios_base [C++], iword
- std::ios_base [C++], precision
- std::ios_base [C++], pword
- std::ios_base [C++], register_callback
- std::ios_base [C++], setf
- std::ios_base [C++], sync_with_stdio
- std::ios_base [C++], unsetf
- std::ios_base [C++], width
- std::ios_base [C++], xalloc
ms.assetid: 0f9e0abc-f70f-49bc-aa1f-003859f56cfe
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 39098fc501ba94c4fa2cd6cf779e7c5c71cc2f1d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iosbase-class"></a>Classe ios_base
A classe descreve as funções membro e de armazenamento comuns aos fluxos de entrada e de saída que não dependem dos parâmetros do modelo. (A classe de modelo [basic_ios](../standard-library/basic-ios-class.md) descreve o que é comum e depende dos parâmetros do modelo.)  
  
 Um objeto da classe ios_base armazena informações de formatação, que consistem em:  
  
-   Sinalizadores de formato em um objeto do tipo [fmtflags](#fmtflags).  
  
-   Uma máscara de exceção em um objeto do tipo [iostate](#iostate).  
  
-   Uma largura de campo em um objeto do tipo `int`.  
  
-   Uma precisão de exibição em um objeto do tipo `int`.  
  
-   Um objeto de localidade em um objeto do tipo **locale**.  
  
-   Duas matrizes extensíveis, com elementos do tipo **long** e ponteiro `void`.  
  
 Um objeto da classe ios_base também armazena informações de estado de fluxo, em um objeto do tipo [iostate](#iostate), e uma pilha de retorno de chamada.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[ios_base](#ios_base)|Constrói objetos `ios_base`.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[event_callback](#event_callback)|Descreve uma função passada para [register_call](#register_callback).|  
|[fmtflags](#fmtflags)|Constantes para especificar a aparência da saída.|  
|[iostate](#iostate)|Define constantes que descrevem o estado de um fluxo.|  
|[openmode](#openmode)|Descreve como interagir com um fluxo.|  
|[seekdir](#seekdir)|Especifica o ponto de início para operações de deslocamento.|  
  
### <a name="enums"></a>Enums  
  
|||  
|-|-|  
|[event](#event)|Especifica tipos de evento.|  
  
### <a name="constants"></a>Constantes  
  
|||  
|-|-|  
|[adjustfield](#fmtflags)|Um bitmask definido como `internal` &#124; `left` &#124; `right`.|  
|[app](#openmode)|Especifica a busca até o final de um fluxo antes de cada inserção.|  
|[ate](#openmode)|Especifica a busca até o final de um fluxo quando seu objeto de controle é criado.|  
|[badbit](#iostate)|Registra uma perda de integridade do buffer do fluxo.|  
|[basefield](#fmtflags)|Um bitmask definido como `dec` &#124; `hex` &#124; `oct`.|  
|[beg](#seekdir)|Especifica a busca relativa ao início de uma sequência.|  
|[binary](#openmode)|Especifica que um arquivo deve ser lido como um fluxo binário, em vez de um fluxo de texto.|  
|[boolalpha](#fmtflags)|Especifica a inserção ou extração de objetos do tipo `bool` como nomes (como `true` e `false`), e não como valores numéricos.|  
|[cur](#seekdir)|Especifica a busca em relação à posição atual dentro de uma sequência.|  
|[dec](#fmtflags)|Especifica a inserção ou extração de valores inteiros em formato decimal.|  
|[end](#seekdir)|Especifica a busca relativa ao final de uma sequência.|  
|[eofbit](#iostate)|Registra o final do arquivo durante a extração de um fluxo.|  
|[failbit](#iostate)|Registra uma falha ao extrair um campo válido de um fluxo.|  
|[fixed](#fmtflags)|Especifica a inserção de valores de ponto flutuante no formato de ponto fixo (sem nenhum campo expoente).|  
|[floatfield](#fmtflags)|Um bitmask definido como `fixed` &#124; `scientific`|  
|[goodbit](#iostate)|Todos os bits de estado são limpos.|  
|[hex](#fmtflags)|Especifica a inserção ou extração de valores inteiros em formato hexadecimal.|  
|[in](#openmode)|Especifica a extração de um fluxo.|  
|[internal](#fmtflags)|Preenche uma largura de campo inserindo caracteres de preenchimento em um ponto interno de um campo numérico gerado.|  
|[left](#fmtflags)|Especifica a justificação à esquerda.|  
|[oct](#fmtflags)|Especifica a inserção ou extração de valores inteiros em formato octal.|  
|[out](#openmode)|Especifica a inserção em um fluxo.|  
|[right](#fmtflags)|Especifica a justificação à direita.|  
|[scientific](#fmtflags)|Especifica a inserção de valores de ponto flutuante no formato científico (com um campo expoente).|  
|[showbase](#fmtflags)|Especifica a inserção de um prefixo que revela a base de um campo inteiro gerado.|  
|[showpoint](#fmtflags)|Especifica a inserção incondicional de um ponto decimal em um campo de ponto flutuante gerado.|  
|[showpos](#fmtflags)|Especifica a inserção de um sinal de adição em um campo numérico gerado não negativo.|  
|[skipws](#fmtflags)|Especifica ignorar o espaço em branco à esquerda antes de determinadas extrações.|  
|[trunc](#openmode)|Especifica excluir o conteúdo de um arquivo existente quando seu objeto de controle é criado.|  
|[unitbuf](#fmtflags)|Faz com que a saída seja liberada após cada inserção.|  
|[uppercase](#fmtflags)|Especifica a inserção de equivalentes maiúsculas de letras minúsculas em determinadas inserções.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[failure](#failure)|A classe de membro serve como a classe base para todas as exceções geradas pela função de membro [clear](../standard-library/basic-ios-class.md#clear) na classe de modelo [basic_ios](../standard-library/basic-ios-class.md).|  
|[flags](#flags)|Define ou retorna as configurações de sinalizador atuais.|  
|[getloc](#getloc)|Retorna o objeto de localidade armazenado.|  
|[imbue](#imbue)|Altera a localidade.|  
|[Init](#init)|Cria os objetos iostream padrão quando construído.|  
|[iword](#iword)|Atribui um valor a ser armazenado como um `iword`.|  
|[precision](#precision)|Especifica o número de dígitos a serem exibidos em um número de ponto flutuante.|  
|[pword](#pword)|Atribui um valor a ser armazenado como um `pword`.|  
|[register_callback](#register_callback)|Especifica uma função de retorno de chamada.|  
|[setf](#setf)|Define os sinalizadores especificados.|  
|[sync_with_stdio](#sync_with_stdio)|Garante que operações de iostream e da biblioteca em tempo de execução do C ocorram na ordem em que aparecem no código-fonte.|  
|[unsetf](#unsetf)|Faz com que os sinalizadores especificados sejam desativados.|  
|[width](#width)|Define o tamanho do fluxo de saída.|  
|[xalloc](#xalloc)|Especifica que uma variável deve ser parte do fluxo.|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator=](#op_eq)|O operador de atribuição para objetos `ios_base`.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<ios>  
  
 **Namespace:** std  
  
##  <a name="event"></a>  ios_base::event  
 Especifica tipos de evento.  
  
```  
enum event {
    erase_event,
    imbue_event,
    copyfmt_event};  
```  
  
### <a name="remarks"></a>Comentários  
 O tipo é um tipo enumerado que descreve um objeto que pode armazenar o evento de retorno de chamada usado como argumento para uma função registrada com [register_callback](#register_callback). Os valores de eventos distintos são:  
  
- **copyfmt_event**, para identificar um retorno de chamada que ocorre próximo ao final de uma chamada para [copyfmt](../standard-library/basic-ios-class.md#copyfmt), logo antes da [máscara de exceção](../standard-library/ios-base-class.md) ser copiada.  
  
- **erase_event**, para identificar um retorno de chamada que ocorre no início de uma chamada para [copyfmt](../standard-library/basic-ios-class.md#copyfmt), ou no início de uma chamada para o destruidor para **\*this**.  
  
- **imbue_event**, para identificar um retorno de chamada que ocorre no final de uma chamada para [imbue](#imbue), logo antes da função ser retornada.  
  
### <a name="example"></a>Exemplo  
  
  Consulte [register_callback](#register_callback) para ver um exemplo.  
  
##  <a name="event_callback"></a>  ios_base::event_callback  

 Descreve uma função passada para [register_call](#register_callback).  
  
```  
typedef void (__cdecl *event_callback)(
    event _E,  
    ios_base& _Base,  
    int _I);
```  
  
### <a name="parameters"></a>Parâmetros  
 *_E*  
 O [evento](#event).  
  
 `_Base`  
 O fluxo no qual o evento foi chamado.  
  
 *_I*  
 Um número definido pelo usuário.  
  
### <a name="remarks"></a>Comentários  
  
 O tipo descreve um ponteiro para uma função que pode ser registrada com [register_callback](#register_callback). Esse tipo de função não deve gerar uma exceção.  
  
### <a name="example"></a>Exemplo  
  
  Consulte [register_call](#register_callback) para ver um exemplo que usa `event_callback`.  
  
##  <a name="failure"></a>  ios_base::failure  
  
 A classe `failure` define a classe base para os tipos de todos os objetos gerados como exceções, por funções na biblioteca `iostreams`, para relatar erros detectados durante operações de buffer de fluxo.  
  
```  
namespace std {  
    class failure : public system_error {  
    public:  
        explicit failure(
            const string& _Message,  
            const error_code& _Code = io_errc::stream);

        explicit failure(
            const char* str,  
            const error_code& _Code = io_errc::stream);
    };
}  
```  
  
### <a name="remarks"></a>Comentários  

 O valor retornado por `what()` é uma cópia de `_Message`, possivelmente aumentada com um teste baseado em `_Code`. Se `_Code` não for especificado, o valor padrão será `make_error_code(io_errc::stream)`.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_failure.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main ( )  
{  
    using namespace std;  
    fstream file;  
    file.exceptions(ios::failbit);  
    try  
    {  
        file.open( "rm.txt", ios_base::in );  
        // Opens nonexistent file for reading  
    }  
    catch( ios_base::failure f )  
    {  
        cout << "Caught an exception: " << f.what() << endl;  
    }  
}  
```  
  
```Output  
Caught an exception: ios_base::failbit set  
```  
  
##  <a name="flags"></a>  ios_base::flags  
  
 Define ou retorna as configurações de sinalizador atuais.  
  
```  
fmtflags flags() const;
fmtflags flags(fmtflags fmtfl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `fmtfl`  
 A nova configuração `fmtflags`.  
  
### <a name="return-value"></a>Valor de retorno  
  
 A configuração `fmtflags` anterior ou atual.  
  
### <a name="remarks"></a>Comentários  
  
 Consulte [ios_base::fmtflags](#fmtflags) para obter uma lista dos sinalizadores.  
  
 A primeira função membro retorna os sinalizadores de formato armazenados. A segunda função membro armazena `fmtfl` nos sinalizadores de formato e retorna seu valor armazenado anterior.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_flags.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main ( )  
{  
    using namespace std;  
    cout << cout.flags( ) << endl;  
    cout.flags( ios::dec | ios::boolalpha );  
    cout << cout.flags( );  
}    
```  
  
```Output  
513  
16896  
```  
  
##  <a name="fmtflags"></a>  ios_base::fmtflags  
  
 Constantes para especificar a aparência da saída.  
  
```
class ios_base {  
public:  
   typedef implementation-defined-bitmask-type fmtflags;  
   static const fmtflags boolalpha;  
   static const fmtflags dec;  
   static const fmtflags fixed;  
   static const fmtflags hex;  
   static const fmtflags internal;  
   static const fmtflags left;  
   static const fmtflags oct;  
   static const fmtflags right;  
   static const fmtflags scientific;  
   static const fmtflags showbase;  
   static const fmtflags showpoint;  
   static const fmtflags showpos;  
   static const fmtflags skipws;  
   static const fmtflags unitbuf;  
   static const fmtflags uppercase;  
   static const fmtflags adjustfield;  
   static const fmtflags basefield;  
   static const fmtflags floatfield;  
   // ...  
};  
```  
  
### <a name="remarks"></a>Comentários  
  
 Dá suporte aos manipuladores em [ios](../standard-library/ios.md).  
  
 O tipo é um tipo de bitmask que descreve um objeto que pode armazenar sinalizadores de formato. Os valores de sinalizador (elementos) distintos são:  
  
- `dec`, para inserir ou extrair valores inteiros em formato decimal.  
  
- `hex`, para inserir ou extrair valores inteiros em formato hexadecimal.  
  
- `oct`, para inserir ou extrair valores inteiros em formato octal.  
  
- `showbase`, para inserir um prefixo que revela a base de um campo inteiro gerado.  
  
- `internal`, para preencher uma largura de campo inserindo caracteres de preenchimento em um ponto interno de um campo numérico gerado. (Para obter informações sobre como configurar a largura do campo, consulte [setw](../standard-library/iomanip-functions.md#setw)).  
  
- `left`, para preencher uma largura de campo, conforme necessário, inserindo caracteres de preenchimento no final de um campo gerado (justificação à esquerda).  
  
- `right`, para preencher uma largura de campo, conforme necessário, inserindo caracteres de preenchimento no início de um campo gerado (justificação à direita).  
  
- `boolalpha`, para inserir ou extrair objetos do tipo `bool` como nomes (como `true` e `false`), e não como valores numéricos.  
  
- `fixed`, para inserir valores de ponto flutuante no formato de ponto fixo (sem nenhum campo expoente).  
  
- `scientific`, para inserir valores de ponto flutuante no formato científico (com um campo expoente).  
  
- `showpoint`, para inserir de forma incondicional um ponto decimal em um campo de ponto flutuante gerado.  
  
- `showpos`, para inserir um sinal de adição em um campo numérico gerado não negativo.  
  
- `skipws`, para ignorar o espaço em branco à esquerda antes de determinadas extrações.  
  
- `unitbuf`, para liberar a saída após cada inserção.  
  
- `uppercase`, para inserir equivalentes maiúsculas de letras minúsculas em determinadas inserções.  
  
 Além disso, diversos valores úteis são:  
  
- `adjustfield`, um bitmask definido como `internal` &#124; `left` &#124; `right`  
  
- `basefield`, definido como `dec` &#124; `hex` &#124; `oct`  
  
- `floatfield`, definido como `fixed` &#124; `scientific`  
  
 Para ver exemplos de funções que modificam esses sinalizadores de formato, consulte [\<iomanip >](../standard-library/iomanip.md).  
  
##  <a name="getloc"></a>  ios_base::getloc  
  
 Retorna o objeto de localidade armazenado.  
  
```  
locale getloc() const;
```  
  
### <a name="return-value"></a>Valor de retorno  
  
 O objeto de localidade armazenado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_getlock.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    cout << cout.getloc( ).name( ).c_str( ) << endl;  
}  
```  
  
```Output  
C  
```  
  
##  <a name="imbue"></a>  ios_base::imbue  

 Altera a localidade.  
  
```  
locale imbue(const locale& _Loc);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Loc`  
 A nova configuração de localidade.  
  
### <a name="return-value"></a>Valor de retorno  
  
 A localidade anterior.  
  
### <a name="remarks"></a>Comentários  
  
 A função de membro armazena `_Loc` no objeto de localidade e, em seguida, relata o evento de retorno de chamada e `imbue_event`. Ela retorna o valor armazenado anterior.  
  
### <a name="example"></a>Exemplo  
  
  Consulte [basic_ios::imbue](../standard-library/basic-ios-class.md#imbue) para ver um exemplo.  
  
##  <a name="init"></a>  ios_base::Init  
  
 Cria os objetos iostream padrão quando construído.  
  
```  
class Init { };  
```
  
### <a name="remarks"></a>Comentários  
  
 A classe aninhada descreve um objeto cuja construção garante que os objetos iostreams padrão sejam construídos adequadamente, mesmo antes da execução de um construtor para um objeto estático arbitrário.  
  
##  <a name="ios_base"></a>  ios_base::ios_base  
  
 Constrói objetos ios_base.  
  
```  
ios_base();
```  
  
### <a name="remarks"></a>Comentários  
  
 O construtor (protegido) não faz nada. Uma chamada posterior a **basic_ios::**[init](../standard-library/basic-ios-class.md#init) deve inicializar o objeto antes de ser destruída com segurança. Sendo assim, o único uso seguro da classe ios_base é como uma classe base para a classe de modelo [basic_ios](../standard-library/basic-ios-class.md).  
  
##  <a name="iostate"></a>  ios_base::iostate  
  
 O tipo das constantes que descrevem o estado de um fluxo.  
  
```  
class ios_base {  
public:  
   typedef implementation-defined-bitmask-type iostate;  
   static const iostate badbit;  
   static const iostate eofbit;  
   static const iostate failbit;  
   static const iostate goodbit;  
   // ...  
};  
```  
  
### <a name="remarks"></a>Comentários  
  
 O tipo é um tipo de bitmask que descreve um objeto que pode armazenar informações de estado do fluxo. Os valores de sinalizador (elementos) distintos são:  
  
- `badbit`, para registrar uma perda de integridade do buffer do fluxo.  
  
- `eofbit`, para registrar o final do arquivo durante a extração de um fluxo.  
  
- `failbit`, para registrar uma falha ao extrair um campo válido de um fluxo.  
  
 Além disso, um valor útil é `goodbit`, em que nenhum dos bits mencionados anteriormente são definidos (`goodbit` deverá ser zero).  
  
##  <a name="iword"></a>  ios_base::iword  
  
 Atribui um valor a ser armazenado como um `iword`.  
  
```  
long& iword(int idx);
```  
  
### <a name="parameters"></a>Parâmetros  
 `idx`  
 O índice do valor a ser armazenado como um `iword`.  
  
### <a name="remarks"></a>Comentários  
  
 A função de membro retorna uma referência ao elemento `idx` da matriz extensível com elementos do tipo **long**. Todos os elementos estão efetivamente presentes e inicialmente armazenam o valor zero. A referência retornada é inválida após a chamada seguinte para `iword` para o objeto, após o objeto ser alterado por uma chamada para **basic_ios::**[copyfmt](../standard-library/basic-ios-class.md#copyfmt), ou após o objeto ser destruído.  
  
 Se `idx` for negativo ou se um armazenamento exclusivo não estiver disponível para o elemento, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)**(badbit)** e retornará uma referência que pode não ser exclusiva.  
  
 Para obter um índice exclusivo, para uso em todos os objetos do tipo `ios_base`, chame [xalloc](#xalloc).  
  
### <a name="example"></a>Exemplo  
  
  Consulte [xalloc](#xalloc) para ver um exemplo de como usar `iword`.  
  
##  <a name="openmode"></a>  ios_base::openmode  
  
 Descreve como interagir com um fluxo.  
  
```  
class ios_base {  
public:  
   typedef implementation-defined-bitmask-type iostate;  
   static const iostate badbit;  
   static const iostate eofbit;  
   static const iostate failbit;  
   static const iostate goodbit;  
   // ...  
};  
```  
  
### <a name="remarks"></a>Comentários  
  
 O tipo é um `bitmask type` que descreve um objeto que pode armazenar o modo de abertura de vários objetos iostreams. Os valores de sinalizador (elementos) distintos são:  
  
- **app**, para buscar até o final de um fluxo antes de cada inserção.  
  
- **ate**, para buscar até o final de um fluxo quando seu objeto de controle é criado.  
  
- **binary**, para ler um arquivo como um fluxo binário, e não como um fluxo de texto.  
  
- **in**, para permitir a extração de um fluxo.  
  
- **out**, para permitir a inserção em um fluxo.  
  
- **trunc**, para excluir o conteúdo de um arquivo existente quando seu objeto de controle é criado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_openmode.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main ( )  
{  
    using namespace std;  
    fstream file;  
    file.open( "rm.txt", ios_base::out | ios_base::trunc );  
    
    file << "testing";  
}    
```  
  
##  <a name="op_eq"></a>  ios_base::operator=  

 O operador de atribuição para objetos ios_base.  
  
```  
ios_base& operator=(const ios_base& right);
```  
  
### <a name="parameters"></a>Parâmetros  
 `right`  
 Um objeto do tipo `ios_base`.  
  
### <a name="return-value"></a>Valor de retorno  
  
 O objeto ao qual a atribuição está sendo feita.  
  
### <a name="remarks"></a>Comentários  
  
 O operador copia as informações de formatação armazenadas, fazendo uma nova cópia de qualquer matriz extensível. Ele retorna **\*this**. Observe que a pilha de retorno de chamada não é copiada.  
  
 Esse operador é usado apenas por classes derivadas de `ios_base`.  
  
##  <a name="precision"></a>  ios_base::precision  
  
 Especifica o número de dígitos a serem exibidos em um número de ponto flutuante.  
  
```  
streamsize precision() const;
streamsize precision(streamsize _Prec);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Prec`  
 O número de dígitos significativos a serem exibidos, ou o número de dígitos após o ponto decimal em notação fixa.  
  
### <a name="return-value"></a>Valor de retorno  
  
 A primeira função membro retorna a [precisão de exibição](../standard-library/ios-base-class.md) armazenada. A segunda função membro armazena `_Prec` na precisão de exibição e retorna seu valor armazenado anterior.  
  
### <a name="remarks"></a>Comentários  
  
 Números de ponto flutuante são exibidos em notação fixa com [fixed](../standard-library/ios-functions.md#fixed).  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_precision.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    float i = 31.31234F;  
    
    cout.precision( 3 );  
    cout << i << endl;          // display three significant digits  
    cout << fixed << i << endl; // display three digits after decimal  
                                // point  
}  
```  
  
```Output  
31.3  
31.312  
```  
  
##  <a name="pword"></a>  ios_base::pword  
  
 Atribui um valor a ser armazenado como um `pword`.  
  
```  
void *& pword(int _Idx);
```  
  
### <a name="parameters"></a>Parâmetros  
 `_Idx`  
 O índice do valor a ser armazenado como `pword`.  
  
### <a name="remarks"></a>Comentários  
  
 A função de membro retorna uma referência ao elemento _ *Idx* da matriz extensível com elementos do tipo ponteiro `void`. Todos os elementos estão efetivamente presentes e, inicialmente, armazenam o ponteiro nulo. A referência retornada é inválida após a chamada seguinte para `pword` para o objeto, após o objeto ser alterado por uma chamada para **basic_ios::**[copyfmt](../standard-library/basic-ios-class.md#copyfmt), ou após o objeto ser destruído.  
  
 Se _ *Idx* for negativo ou se um armazenamento exclusivo não estiver disponível para o elemento, a função chamará [setstate](../standard-library/basic-ios-class.md#setstate)**(badbit)** e retornará uma referência que pode não ser exclusiva.  
  
 Para obter um índice exclusivo, para uso em todos os objetos do tipo `ios_base`, chame [xalloc](#xalloc).  
  
### <a name="example"></a>Exemplo  
  
  Consulte [xalloc](#xalloc) para ver um exemplo de como usar `pword`.  
  
##  <a name="register_callback"></a>  ios_base::register_callback  
  
 Especifica uma função de retorno de chamada.  
  
```  
void register_callback(
    event_callback pfn, int idx);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pfn`  
 Ponteiro para a função de retorno.  
  
 `idx`  
 Um número definido pelo usuário.  
  
### <a name="remarks"></a>Comentários  
  
 A função de membro envia o par `{pfn, idx}` para a pilha de retorno de chamada armazenado [pilha de retorno de chamada](../standard-library/ios-base-class.md). Quando um evento de retorno de chamada **ev** for relatado, as funções são chamadas, na ordem inversa de registro, pela expressão `(*pfn)(ev, *this, idx)`.  
 
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_register_callback.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
using namespace std;  
  
void callback1( ios_base::event e, ios_base& stream, int arg )  
{  
    cout << "in callback1" << endl;  
    switch ( e )  
    {  
    case ios_base::erase_event:  
        cout << "an erase event" << endl;  
        break;  
    case ios_base::imbue_event:  
        cout << "an imbue event" << endl;  
        break;  
    case ios_base::copyfmt_event:  
        cout << "an copyfmt event" << endl;  
        break;  
    };  
}  
  
void callback2( ios_base::event e, ios_base& stream, int arg )  
{  
    cout << "in callback2" << endl;  
    switch ( e )  
    {  
    case ios_base::erase_event:  
        cout << "an erase event" << endl;  
        break;  
    case ios_base::imbue_event:  
        cout << "an imbue event" << endl;  
        break;  
    case ios_base::copyfmt_event:  
        cout << "an copyfmt event" << endl;  
        break;  
    };  
}  
  
int main( )  
{  
    // Make sure the imbue will not throw an exception  
    // assert( setlocale( LC_ALL, "german" )!=NULL );  
    
    cout.register_callback( callback1, 0 );  
    cin.register_callback( callback2, 0 );  
    
    try  
    {  
        // If no exception because the locale's not found,  
        // generate an imbue_event on callback1  
        cout.imbue(locale("german"));  
    }  
    catch(...)  
    {  
        cout << "exception" << endl;  
    }  
    
    // This will  
    // (1) erase_event on callback1  
    // (2) copyfmt_event on callback2  
    cout.copyfmt(cin);  
    
    // We get two erase events from callback2 at the end because  
    // both cin and cout have callback2 registered when cin and cout  
    // are destroyed at the end of program.  
}  
```  
  
```Output  
in callback1  
an imbue event  
in callback1  
an erase event  
in callback2  
an copyfmt event  
in callback2  
an erase event  
in callback2  
an erase event  
```  
 
##  <a name="seekdir"></a> ios_base::seekdir  
  
Especifica o ponto de início para operações de deslocamento.  
  
```  
namespace std {  
    class ios_base {  
    public:  
        typedef implementation-defined-enumerated-type seekdir;  
        static const seekdir beg;  
        static const seekdir cur;  
        static const seekdir end;  
        // ...  
    };  
}  
```  
 
### <a name="remarks"></a>Comentários  
  
O tipo é um tipo enumerado que descreve um objeto que pode armazenar o modo de busca usado como um argumento para as funções de membro de várias classes iostream. Os valores de sinalizador distintos são:  
 
- **beg**, para buscar (alterar a posição de leitura ou gravação atual) com relação ao início de uma sequência (matriz, fluxo ou arquivo).  
 
- **cur**, para buscar em relação à posição atual dentro de uma sequência.  
 
- **end**, para buscar em relação ao final de uma sequência.  
 
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_seekdir.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <fstream>  
  
int main ( )  
{  
    using namespace std;  
    fstream file;  
    file.open( "rm.txt", ios_base::out | ios_base::trunc );  
    
    file << "testing";  
    file.seekp( 0, ios_base::beg );  
    file << "a";  
    file.seekp( 0, ios_base::end );  
    file << "a";  
}  
```  
  
##  <a name="setf"></a> ios_base::setf  
  
Define os sinalizadores especificados.  

```    
fmtflags setf(  
    fmtflags _Mask  
);  
fmtflags setf(  
    fmtflags _Mask,  
    fmtflags _Unset  
);  
```  
 
### <a name="parameters"></a>Parâmetros  
 `_Mask`  
    Os sinalizadores a serem ativados.  
 
 *_Unset* os sinalizadores para desativar.  
 
### <a name="return-value"></a>Valor de retorno  
    The previous format flags  
 
### <a name="remarks"></a>Comentários  
    The first member function effectively calls [flags](#flags)(_ *Mask* &#124; \_ *Flags*) (set selected bits) and then returns the previous format flags. The second member function effectively calls **flags**(\_ *Mask* **& fmtfl, flags& ~**`_Mask`) (replace selected bits under a mask) and then returns the previous format flags.  
 
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_setf.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    int i = 10;  
    cout << i << endl;  
    
    cout.unsetf( ios_base::dec );  
    cout.setf( ios_base::hex );  
    cout << i << endl;  
    
    cout.setf( ios_base::dec );  
    cout << i << endl;  
    cout.setf( ios_base::hex, ios_base::dec );  
    cout << i << endl;  
}  
```  
 
##  <a name="sync_with_stdio"></a> ios_base::sync_with_stdio  
  
Garante que operações de iostream e da biblioteca em tempo de execução do C ocorram na ordem em que aparecem no código-fonte.  
  
```  
static bool sync_with_stdio(  
   bool _Sync = true  
);  
```  
 
### <a name="parameters"></a>Parâmetros  
 `_Sync`  
    Se todos os fluxos estão sincronizados com **stdio**.  
 
### <a name="return-value"></a>Valor de retorno  
    Previous setting for this function.  
 
### <a name="remarks"></a>Comentários  
    The static member function stores a **stdio** sync flag, which is initially **true**. When **true**, this flag ensures that operations on the same file are properly synchronized between the [iostreams](../standard-library/iostreams-conventions.md) functions and those defined in the C++ Standard Library. Otherwise, synchronization may or may not be guaranteed, but performance may be improved. The function stores `_Sync` in the **stdio** sync flag and returns its previous stored value. You can call it reliably only before performing any operations on the standard streams.  
 
##  <a name="unsetf"></a> ios_base::unsetf  
  
Faz com que os sinalizadores especificados sejam desativados.  
  
```  
void unsetf(  
   fmtflags _Mask  
);  
```  
 
### <a name="parameters"></a>Parâmetros  
 `_Mask`  
    Os sinalizadores que você deseja desativar.  
 
### <a name="remarks"></a>Comentários  
    The member function effectively calls [flags](#flags)(`~`*_Mask* **& flags**) (clear selected bits).  
 
### <a name="example"></a>Exemplo  
    See [ios_base::setf](#setf) for a sample of using `unsetf`.  
 
##  <a name="width"></a> ios_base::width  
  
Define o tamanho do fluxo de saída.  
  
```  
streamsize width( ) const;  
streamsize width(  
   streamsize _Wide  
);  
```  
 
### <a name="parameters"></a>Parâmetros  
 `_Wide`  
    O tamanho desejado do fluxo de saída.  
 
### <a name="return-value"></a>Valor de retorno  

    The current width setting.  
 
### <a name="remarks"></a>Comentários  

    The first member function returns the stored field width. The second member function stores `_Wide` in the field width and returns its previous stored value.  
 
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_width.cpp  
// compile with: /EHsc  
#include <iostream>  
  
int main( ) {  
    using namespace std;  
    
    cout.width( 20 );  
    cout << cout.width( ) << endl;  
    cout << cout.width( ) << endl;  
}  
```  
  
```Output  
20  
0  
```  
 
##  <a name="xalloc"></a> ios_base::xalloc  
  
    Specifies that a variable is part of the stream.  
  
```  
static int xalloc( );  
```  
 
### <a name="return-value"></a>Valor de retorno  
    The static member function returns a stored static value, which it increments on each call.  
 
### <a name="remarks"></a>Comentários  
    You can use the return value as a unique index argument when calling the member functions [iword](#iword) or [pword](#pword).  
 
### <a name="example"></a>Exemplo  
  
```cpp  
// ios_base_xalloc.cpp  
// compile with: /EHsc  
// Lets you store user-defined information.  
// iword, jword, xalloc  
#include <iostream>  
  
int main( )  
{  
    using namespace std;  
    
    static const int i = ios_base::xalloc();  
    static const int j = ios_base::xalloc();  
    cout.iword( i ) = 11;  
    cin.iword( i ) = 13;  
    cin.pword( j ) = "testing";  
    cout << cout.iword( i ) << endl;  
    cout << cin.iword( i ) << endl;  
    cout << ( char * )cin.pword( j ) << endl;  
}    
```  
  
```Output  
11  
13  
testing  
```  
  
## <a name="see-also"></a>Consulte também  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Programação de iostream](../standard-library/iostream-programming.md)   
 [Convenções de iostreams](../standard-library/iostreams-conventions.md)
